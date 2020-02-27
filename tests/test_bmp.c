/**
 * @file test_bmp.c
 * @author Renan Masashi Yamaguchi
 * @brief Test bmp functions
 * @version 0.1
 * @date 2020-02-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "util.h"
#include "bmp.h"

void testBmp()
{
    FILE *rd_fp, *bmp24_fp;
    byte rd[IMG_MAXBUF] = {};
    byte bmp24[IMG_MAX24BUF] = {};
    byte wr[IMG_MAX24BUF] = {};
    BMP bmp;

    rd_fp = fopen("grf/img32.bmp", "rb");
    bmp24_fp = fopen("grf/img24.bmp", "rb");

    PRINT("%lu", fread(rd, sizeof(byte), IMG_MAXBUF, rd_fp));
    PRINT("%lu", fread(bmp24, sizeof(byte), IMG_MAX24BUF, bmp24_fp));
    fclose(rd_fp);
    fclose(bmp24_fp);

    PRINT("%d", BMPto24bpp(rd, wr));
    memcpy(bmp.data, wr, sizeof(BMPHeader));

    ASSERT(memcmp(wr, bmp24, bmp.Header.size));
}