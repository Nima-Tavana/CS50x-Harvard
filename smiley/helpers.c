#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int w = 0; w < width; w++)
    {
        for (int h = 0; h < height; h++)
        {
            // checking if pixels are in white color rgb = 0,0,0
            if (image[w][h].rgbtRed == 0 && image[w][h].rgbtGreen == 0 && image[w][h].rgbtBlue == 0)
            {
                image[w][h].rgbtRed = 43;
                image[w][h].rgbtGreen = 4;
                image[w][h].rgbtBlue = 43;
            }

            // checking if pixels are in black color rgb = 256 ,256,256
            if (image[w][h].rgbtRed == 255 && image[w][h].rgbtGreen == 255 && image[w][h].rgbtBlue == 255)
            {
                image[w][h].rgbtRed = 1;
                image[w][h].rgbtGreen = 3;
                image[w][h].rgbtBlue = 14;
            }
        }
    }
}