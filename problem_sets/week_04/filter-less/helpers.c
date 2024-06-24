#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Avg of Red, Green, Blue
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;
            int avg_rgb = (int) round((r + g + b) / 3.0);

            // Update pixel
            image[i][j].rgbtRed = avg_rgb;
            image[i][j].rgbtGreen = avg_rgb;
            image[i][j].rgbtBlue = avg_rgb;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Red, Green, Blue Values
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            // Sepia red value
            int sepiaRed = (int) round((.393 * r) + (.769 * g) + (.189 * b));
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            // Sepia green value
            int sepiaGreen = (int) round((.349 * r) + (.686 * g) + (.168 * b));
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            // Sepia blue value
            int sepiaBlue = (int) round((.272 * r) + (.534 * g) + (.131 * b));
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Update pixel
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int half_width = (int) round(width / 2.0);
        for (int j = 0; j < half_width; j++)
        {
            // temp value
            RGBTRIPLE temp = image[i][j];

            // Flip pixel
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Blur the image
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // rgb values
            int red = 0;
            int green = 0;
            int blue = 0;
            float counter = 0.0;

            // average adjecent 9x9 pixels
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    int existed_row = row + i;
                    int existed_col = col + j;

                    // only existed pixel
                    if ((existed_row >= 0 && existed_row <= (height - 1)) && (existed_col >= 0 && existed_col <= (width - 1)))
                    {
                        red += copy[existed_row][existed_col].rgbtRed;
                        green += copy[existed_row][existed_col].rgbtGreen;
                        blue += copy[existed_row][existed_col].rgbtBlue;
                        counter++;
                    }
                }
            }
            image[row][col].rgbtRed = (int) round(red / counter);
            image[row][col].rgbtGreen = (int) round(green / counter);
            image[row][col].rgbtBlue = (int) round(blue / counter);
        }
    }

    return;
}
