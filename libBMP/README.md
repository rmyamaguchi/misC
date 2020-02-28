# libBMP

An implementation example of a function to transform BMPs 8 or 32 bpp to 24 bpp.

## 8 bpp

An 8 bpp BMP has a lookup table for its colors just after the BMP header. These colors are 4 bytes long (BGRA in Big end).

## 32 bpp

The resulting color of the 24 bpp BMP is a weighted sum using the alpha value to measure the amount of contribution the background color and the image color have in the final RGB value.