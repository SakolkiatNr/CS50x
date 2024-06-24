#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            int avg_rgb = (int) round((red + green + blue) / 3.0);

            // Update pixel
            image[i][j].rgbtRed = avg_rgb;
            image[i][j].rgbtGreen = avg_rgb;
            image[i][j].rgbtBlue = avg_rgb;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int half_width = (int) round(width / 2.0);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < half_width; j++)
        {
            RGBTRIPLE temp = image[i][j];

            // Flip
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // temporary image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Blur image
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // RGB
            int red = 0;
            int green = 0;
            int blue = 0;
            float counter = 0.0;

            // avg 9x9 around current pixel
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    int erow = row + i;
                    int ecol = col + j;

                    // calculate only existed row&col
                    if ((erow >= 0 && erow <= (height - 1)) && (ecol >= 0 && ecol <= (width - 1)))
                    {
                        red += temp[erow][ecol].rgbtRed;
                        green += temp[erow][ecol].rgbtGreen;
                        blue += temp[erow][ecol].rgbtBlue;
                        counter++;
                    }
                }
            }

            // Update image
            image[row][col].rgbtRed = (int) round(red / counter);
            image[row][col].rgbtGreen = (int) round(green / counter);
            image[row][col].rgbtBlue = (int) round(blue / counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // temporary image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Row cycling
    for (int row = 0; row < height; row++)
    {
        // Column cycling
        for (int col = 0; col < width; col++)
        {
            // Implement Sobel operator to each pixel
            int gx_red = 0;
            int gx_green = 0;
            int gx_blue = 0;

            int gy_red = 0;
            int gy_green = 0;
            int gy_blue = 0;

            // Cycle 9x9 around current pixel
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    // existed row & column
                    int erow = row + i;
                    int ecol = col + j;

                    // calculate only existed row&col
                    if ((erow >= 0 && erow <= (height - 1)) && (ecol >= 0 && ecol <= (width - 1)))
                    {
                        // Middle row of Gx
                        if (i == 0)
                        {
                            gx_red += (2 * j * temp[erow][ecol].rgbtRed);
                            gx_green += (2 * j * temp[erow][ecol].rgbtGreen);
                            gx_blue += (2 * j * temp[erow][ecol].rgbtBlue);
                        }
                        // Top and bottom rows of Gx & Gy
                        else
                        {
                            // Gx
                            gx_red += (j * temp[erow][ecol].rgbtRed);
                            gx_green += (j * temp[erow][ecol].rgbtGreen);
                            gx_blue += (j * temp[erow][ecol].rgbtBlue);

                            // Gy top row
                            if (i == -1)
                            {
                                if ((j == -1 || j == 1))
                                {
                                    gy_red += (-1 * temp[erow][ecol].rgbtRed);
                                    gy_green += (-1 * temp[erow][ecol].rgbtGreen);
                                    gy_blue += (-1 * temp[erow][ecol].rgbtBlue);
                                }
                                else
                                {
                                    gy_red += (-2 * temp[erow][ecol].rgbtRed);
                                    gy_green += (-2 * temp[erow][ecol].rgbtGreen);
                                    gy_blue += (-2 * temp[erow][ecol].rgbtBlue);
                                }
                            }
                            // Gy bottom row
                            if (i == 1)
                            {
                                if ((j == -1 || j == 1))
                                {
                                    gy_red += (1 * temp[erow][ecol].rgbtRed);
                                    gy_green += (1 * temp[erow][ecol].rgbtGreen);
                                    gy_blue += (1 * temp[erow][ecol].rgbtBlue);
                                }
                                else
                                {
                                    gy_red += (2 * temp[erow][ecol].rgbtRed);
                                    gy_green += (2 * temp[erow][ecol].rgbtGreen);
                                    gy_blue += (2 * temp[erow][ecol].rgbtBlue);
                                }
                            }
                        }
                    }
                }
            }
            // calculate Gx
            int gred = (int) round(sqrt(pow(gx_red, 2) + pow(gy_red, 2)));
            int ggreen = (int) round(sqrt(pow(gx_green, 2) + pow(gy_green, 2)));
            int gblue = (int) round(sqrt(pow(gx_blue, 2) + pow(gy_blue, 2)));

            // Value cap
            if (gred > 255)
            {
                gred = 255;
            }
            if (ggreen > 255)
            {
                ggreen = 255;
            }
            if (gblue > 255)
            {
                gblue = 255;
            }

            // Update image
            image[row][col].rgbtRed = gred;
            image[row][col].rgbtGreen = ggreen;
            image[row][col].rgbtBlue = gblue;
        }
    }

    return;
}
