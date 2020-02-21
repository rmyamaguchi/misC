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

/**
 * @brief Computes the Lowest Multiple of a Power of 2 Greater than or Equal to (x)
 * 
 * @param[in] p2 Must be a power of 2 
 * @param[in] x 
 * @return unsigned int The result. Returns 0 if p2 is not a power of 2.
 */
static unsigned int LMp2GE(unsigned int p2, unsigned int x)
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
static unsigned int getNumPads(size_t img_width)
{
    unsigned int ret;
    ret = LMp2GE(4, img_width);
    if (ret)
        ret -= img_width;
    return ret;
}

/**
 * @brief Let us try converting BMPs to 24 bpp.
 * @note Currently supporting only 8 bpp
 * 
 * @param[in] bmp_in Original BMP buffer
 * @param[out] bmp_out Converted BMP
 * 
 * @return int 
 *  0: Success
 *  1: Invalid BMP
 *  2: Too big of a BMP
 */
int BMPto24bpp(const byte *bmp_in, byte *bmp_out)
{
    BMP BMP8, BMP24;
    byte *read_idx, *write_idx, *color_tab;
    int read_inline_idx, write_inline_idx;
    unsigned int read_num_pads, write_num_pads;
    int i;

    /* Get BMP header first */
    memcpy(BMP8.data, bmp_in, sizeof(BMPHeader));

    /* Check BMP header */
    if (BMP8.Header.type != 0x4d42)
        return 1;
    /* Check size of file */
    if (BMP8.Header.size > PRN_IMG_MAXBUFF)
        return 2;
    /* Check bpp field */
    if (BMP8.Header.bits_per_pixel != 8)
    {
        memcpy(bmp_out, bmp_in, BMP8.Header.size);
        if (BMP8.Header.bits_per_pixel == 24)
            return 0;
        else
            return 1;
    }

    /* Get the remaining of data */
    memcpy(BMP8.data, bmp_in, BMP8.Header.size);

    /* Go to beginning of data */
    read_idx = BMP8.data + BMP8.Header.offset;
    write_idx = BMP24.data + sizeof(BMPHeader);
    color_tab = (byte *)((unsigned long)&BMP8.Header.dib_header_size + BMP8.Header.dib_header_size);
    read_inline_idx = 0;  /* Index of byte in write line */
    write_inline_idx = 0; /* Index of byte in read line */

    /* Check if padding exists in BMP8 */
    read_num_pads = getNumPads(BMP8.Header.width_px);
    /* Check if padding is necessary in BMP24 */
    write_num_pads = getNumPads(BMP8.Header.width_px * 3);

    /* 8 bpp -> 24 bpp */
    while (read_idx < BMP8.data + BMP8.Header.size &&
           write_idx < BMP24.data + PRN_IMG_MAX24BUFF - 2)
    {
        /* Skip read_num_pads bytes when end of line */
        if (write_inline_idx >= BMP8.Header.width_px * 1)
        {
            for (i = 0; i < read_num_pads; i++)
                read_idx++;
            write_inline_idx = 0;
        }
        /* Get (4 byte) color in BMP8 color table [*read_idx] */
        if (read_inline_idx < BMP8.Header.width_px * 3)
        {
            memcpy(write_idx, color_tab + *read_idx * 4, 3);
            read_idx++;
            write_inline_idx++;
            write_idx += 3;
            read_inline_idx += 3;
        }
        else /* Writes write_num_pads bytes as 0x00 */
        {
            for (i = 0; i < write_num_pads; i++)
                *(write_idx++) = 0x00;
            read_inline_idx = 0;
        }
    }

    /* Build the new header */
    BMP24.Header.type = 0x4d42;
    BMP24.Header.size = write_idx - BMP24.data;
    BMP24.Header.reserved1 = 0;
    BMP24.Header.reserved2 = 0;
    BMP24.Header.dib_header_size = 40;
    BMP24.Header.offset = sizeof(BMPHeader);
    BMP24.Header.width_px = BMP8.Header.width_px;
    BMP24.Header.height_px = BMP8.Header.height_px;
    BMP24.Header.num_planes = 1;
    BMP24.Header.bits_per_pixel = 24;
    BMP24.Header.compression = 0;
    BMP24.Header.image_size_bytes = BMP24.Header.size - BMP24.Header.offset;
    BMP24.Header.x_resolution_ppm = BMP8.Header.x_resolution_ppm;
    BMP24.Header.y_resolution_ppm = BMP8.Header.y_resolution_ppm;
    BMP24.Header.num_colors = 0;
    BMP24.Header.important_colors = 0;

    memcpy(bmp_out, BMP24.data, BMP24.Header.size);

    return 0;
}