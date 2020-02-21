/**
 * @file bmp.h
 * @author rmyamaguchi (rmyamguchi@gmail.com)
 * @brief BMP header
 * @version 0.1
 * @date 2020-02-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef BMP_H
#define BMP_H

#include "util.h"

#define PRN_IMG_MAXBUFF 160000
#define PRN_IMG_MAX24BUFF (3 * PRN_IMG_MAXBUFF)

typedef struct __attribute__((__packed__)) // 54 bytes
{
    __uint16_t type;             // Magic identifier: 0x4d42
    __uint32_t size;             // File size in bytes
    __uint16_t reserved1;        // Not used
    __uint16_t reserved2;        // Not used
    __uint32_t offset;           // Offset to image data in bytes from beginning of file
    __uint32_t dib_header_size;  // DIB Header size in bytes (BITMAPINFOHEADER)
    __int32_t width_px;          // Width of the image
    __int32_t height_px;         // Height of image
    __uint16_t num_planes;       // Number of color planes
    __uint16_t bits_per_pixel;   // Bits per pixel
    __uint32_t compression;      // Compression type
    __uint32_t image_size_bytes; // Image size in bytes
    __int32_t x_resolution_ppm;  // Pixels per meter
    __int32_t y_resolution_ppm;  // Pixels per meter
    __uint32_t num_colors;       // Number of colors
    __uint32_t important_colors; // Important colors
} BMPHeader;

typedef union {
    BMPHeader Header;
    byte data[PRN_IMG_MAX24BUFF];
} BMP;

/**
 * @brief Let us try converting BMPs to 24 bpp.
 * 
 * @param[in] bmp_in Original BMP buffer
 * @param[out] bmp_out Converted BMP
 * 
 * @return int 0: Success
 */
extern int BMPto24bpp(const byte *bmp_in, byte *bmp_out);

#endif /* BMP_H */