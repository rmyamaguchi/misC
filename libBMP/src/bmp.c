/**
 * @file bmp.h
 * @author rmyamaguchi (rmyamguchi@gmail.com)
 * @brief BMP related stuff
 * @version 0.1
 * @date 2020-02-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "bmp.h"

static byte vb_background[] = {0xff, 0xff, 0xff}; /* white */

/**
 * @brief Computes the Lowest Multiple of a Power of 2 Greater than or Equal to (x)
 * 
 * @param[in] p2 Must be a power of 2 
 * @param[in] x 
 * @return unsigned int The result. Returns 0 if p2 is not a power of 2.
 */
static unsigned int lmp2ge(unsigned int p2, unsigned int x)
{
    /* Checks whether p2 is really a Power of 2 */
    if ((p2 != 0) && ((p2 & (p2 - 1)) == 0)) /* e.g. b1000 & b0111 == 0 */
        return ((x - 1) | (p2 - 1)) + 1;
    return 0;
}

/**
 * @brief Computes the number (in bytes) of 0 paddings in a BMP image.
 * 
 * @param[in] img_width in bytes
 * @return unsigned int 
 */
static unsigned int num_pads(size_t img_width)
{
    unsigned int ret;
    ret = lmp2ge(4, img_width);
    if (ret)
        ret -= img_width;
    return ret;
}

/**
 * @brief Get the pixel in a BMP 8bpp and transforms it into a 24bpp one
 * 
 * @param[in] rd_px Pointer to byte[1] read
 * @param[out] wr_px Pointer to byte[3] written
 * @param[in] color_tab Pointer to the beginning of the color table
 * @return int Number of bytes read = 1
 */
static int get_px8b(const byte *rd_px, byte *wr_px, const byte *color_tab)
{
    /* Get color in BMP8 color table [*rd_px] (each color is 4 bytes long) */
    memcpy(wr_px, color_tab + *rd_px * 4, 3);
    return 1;
}

/**
 * @brief Get the pixel in a BMP 32bpp and transforms it into a 24bpp one
 * 
 * @param[in] rd_px Pointer to byte[4] read
 * @param[out] wr_px Pointer to byte[3] written
 * @param[in] color_bg Pointer to a byte[3] as a BGR color of the background
 * @return int Number of bytes read = 4 (BGRA)
 */
static int get_px32b(const byte *rd_px, byte *wr_px, const byte *color_bg)
{
    for (int i = 0; i < 3; i++)
        /* Weighted average: (1 - alpha) * background + alpha * color */
        wr_px[i] = ((0xff - rd_px[ALPHA]) * color_bg[i] + rd_px[ALPHA] * rd_px[i]) / 0xff;
    return 4;
}

/**
 * @brief Convert BMPs to 24 bpp.
 * @note Currently supporting 8 and 32 bpp
 * 
 * @param[in] bmp_in Original BMP buffer
 * @param[out] bmp_out Converted BMP
 * 
 * @return int 
 *  0: Success
 *  1: Invalid BMP
 *  2: Too big of a BMP
 */
int bmp_to_24bpp(const byte *bmp_in, byte *bmp_out)
{
    BMP BMPx, BMP24;
    byte *rd_idx, *wr_idx, *color_ref = NULL;
    int px_idx;
    unsigned int rd_num_pads, wr_num_pads;
    int (*get_px)(const byte *, byte *, const byte *);

    /* Get BMP header first */
    memcpy(BMPx.data, bmp_in, sizeof(BMPHeader));

    /* Check BMP header */
    if (BMPx.Header.type != 0x4d42)
        return 1;
    /* Check size of file */
    if (BMPx.Header.size > IMG_MAXBUF)
        return 2;
    /* Check bpp field */
    switch (BMPx.Header.bits_per_pixel)
    {
    case 8:
        color_ref = (byte *)((unsigned long)&BMPx.Header.dib_header_size + BMPx.Header.dib_header_size);
        get_px = get_px8b;
        break;
    case 32:
        color_ref = vb_background;
        get_px = get_px32b;
        break;
    case 24:
        memcpy(bmp_out, bmp_in, BMPx.Header.size);
        return 0;
    default:
        return 1;
    }

    /* Get remaining data */
    memcpy(BMPx.data, bmp_in, BMPx.Header.size);

    /* Go to beginning of data */
    rd_idx = BMPx.data + BMPx.Header.offset;
    wr_idx = BMP24.data + sizeof(BMPHeader);
    /* Index of pixel in img row */
    px_idx = 0;

    /* Check padding in BMPx */
    rd_num_pads = num_pads(BMPx.Header.bits_per_pixel / 8 * BMPx.Header.width_px);
    /* Check padding in BMP24 */
    wr_num_pads = num_pads(3 * BMPx.Header.width_px);

    while (rd_idx < BMPx.data + BMPx.Header.size &&
           wr_idx < BMP24.data + IMG_MAX24BUF - 2)
    {
        rd_idx += get_px(rd_idx, wr_idx, color_ref);
        wr_idx += 3;
        if (++px_idx >= BMPx.Header.width_px)
        {
            /* Skip rd_num_pads bytes when end of img row */
            rd_idx += rd_num_pads;
            /* Writes wr_num_pads bytes as 0x00 */
            memset(wr_idx, 0x00, wr_num_pads);
            wr_idx += wr_num_pads;
            /* Begin a new img row */
            px_idx = 0;
        }
    }

    /* Build the new header */
    BMP24.Header.type = 0x4d42;
    BMP24.Header.size = wr_idx - BMP24.data;
    BMP24.Header.reserved1 = 0;
    BMP24.Header.reserved2 = 0;
    BMP24.Header.dib_header_size = 40;
    BMP24.Header.offset = sizeof(BMPHeader);
    BMP24.Header.width_px = BMPx.Header.width_px;
    BMP24.Header.height_px = BMPx.Header.height_px;
    BMP24.Header.num_planes = 1;
    BMP24.Header.bits_per_pixel = 24;
    BMP24.Header.compression = 0;
    BMP24.Header.image_size_bytes = BMP24.Header.size - BMP24.Header.offset;
    BMP24.Header.x_resolution_ppm = BMPx.Header.x_resolution_ppm;
    BMP24.Header.y_resolution_ppm = BMPx.Header.y_resolution_ppm;
    BMP24.Header.num_colors = 0;
    BMP24.Header.important_colors = 0;

    memcpy(bmp_out, BMP24.data, BMP24.Header.size);

    return 0;
}