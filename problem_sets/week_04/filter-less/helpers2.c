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
            // Using "Box blur" by averaging the pixel value and neighboring pixels value

            // Top row pixels only average first row pixels and second row pixels
            if (row == 0)
            {
                // Left corner pixel
                if (col == 0)
                {
                    // Get rgb values from the copied image
                    // Red
                    int r1 = copy[row][col].rgbtRed;         // current pixel
                    int r2 = copy[row][col + 1].rgbtRed;     // pixel on the right
                    int r3 = copy[row + 1][col].rgbtRed;     // pixel below
                    int r4 = copy[row + 1][col + 1].rgbtRed; // on the right of below pixel
                    // Green
                    int g1 = copy[row][col].rgbtGreen;         // current pixel
                    int g2 = copy[row][col + 1].rgbtGreen;     // pixel on the right
                    int g3 = copy[row + 1][col].rgbtGreen;     // pixel below
                    int g4 = copy[row + 1][col + 1].rgbtGreen; // on the right of below pixel
                    // Blue
                    int b1 = copy[row][col].rgbtBlue;         // current pixel
                    int b2 = copy[row][col + 1].rgbtBlue;     // pixel on the right
                    int b3 = copy[row + 1][col].rgbtBlue;     // pixel below
                    int b4 = copy[row + 1][col + 1].rgbtBlue; // on the right of below pixel

                    // Average pixels
                    int avg_red = (int) round((r1 + r2 + r3 + r4) / 4.0);
                    int avg_green = (int) round((g1 + g2 + g3 + g4) / 4.0);
                    int avg_blue = (int) round((b1 + b2 + b3 + b4) / 4.0);

                    // Update image
                    image[row][col].rgbtRed = avg_red;
                    image[row][col].rgbtGreen = avg_green;
                    image[row][col].rgbtBlue = avg_blue;
                }
                // Right corner pixel
                else if (col == (width - 1))
                {
                    // Get rgb values from the copied image
                    // Red
                    int r1 = copy[row][col].rgbtRed;         // current pixel
                    int r2 = copy[row][col - 1].rgbtRed;     // pixel on the left
                    int r3 = copy[row + 1][col].rgbtRed;     // pixel below
                    int r4 = copy[row + 1][col - 1].rgbtRed; // on the left of below pixel
                    // Green
                    int g1 = copy[row][col].rgbtGreen;         // current pixel
                    int g2 = copy[row][col - 1].rgbtGreen;     // pixel on the left
                    int g3 = copy[row + 1][col].rgbtGreen;     // pixel below
                    int g4 = copy[row + 1][col - 1].rgbtGreen; // on the left of below pixel
                    // Blue
                    int b1 = copy[row][col].rgbtBlue;         // current pixel
                    int b2 = copy[row][col - 1].rgbtBlue;     // pixel on the left
                    int b3 = copy[row + 1][col].rgbtBlue;     // pixel below
                    int b4 = copy[row + 1][col - 1].rgbtBlue; // on the left of below pixel

                    // Average pixels
                    int avg_red = (int) round((r1 + r2 + r3 + r4) / 4.0);
                    int avg_green = (int) round((g1 + g2 + g3 + g4) / 4.0);
                    int avg_blue = (int) round((b1 + b2 + b3 + b4) / 4.0);

                    // Update image
                    image[row][col].rgbtRed = avg_red;
                    image[row][col].rgbtGreen = avg_green;
                    image[row][col].rgbtBlue = avg_blue;
                }
                // Between corners pixel
                else
                {
                    // Red
                    int r1 = copy[row][col].rgbtRed;         // Current pixel
                    int r2 = copy[row][col - 1].rgbtRed;     // Pixel on the left
                    int r3 = copy[row][col + 1].rgbtRed;     // Pixel on the right
                    int r4 = copy[row + 1][col].rgbtRed;     // Pixel below
                    int r5 = copy[row + 1][col - 1].rgbtRed; // On the left of below pixel
                    int r6 = copy[row + 1][col + 1].rgbtRed; // On the right of below pixel
                    // Green
                    int g1 = copy[row][col].rgbtGreen;         // Current pixel
                    int g2 = copy[row][col - 1].rgbtGreen;     // Pixel on the left
                    int g3 = copy[row][col + 1].rgbtGreen;     // Pixel on the right
                    int g4 = copy[row + 1][col].rgbtGreen;     // Pixel below
                    int g5 = copy[row + 1][col - 1].rgbtGreen; // On the left of below pixel
                    int g6 = copy[row + 1][col + 1].rgbtGreen; // On the right of below pixel
                    // Blue
                    int b1 = copy[row][col].rgbtBlue;         // Current pixel
                    int b2 = copy[row][col - 1].rgbtBlue;     // Pixel on the left
                    int b3 = copy[row][col + 1].rgbtBlue;     // Pixel on the right
                    int b4 = copy[row + 1][col].rgbtBlue;     // Pixel below
                    int b5 = copy[row + 1][col - 1].rgbtBlue; // On the left of below pixel
                    int b6 = copy[row + 1][col + 1].rgbtBlue; // On the right of below pixel

                    // Average pixels
                    int avg_red = (int) round((r1 + r2 + r3 + r4 + r5 + r6) / 6.0);
                    int avg_green = (int) round((g1 + g2 + g3 + g4 + g5 + g6) / 6.0);
                    int avg_blue = (int) round((b1 + b2 + b3 + b4 + b5 + b6) / 6.0);

                    // Update image
                    image[row][col].rgbtRed = avg_red;
                    image[row][col].rgbtGreen = avg_green;
                    image[row][col].rgbtBlue = avg_blue;
                }
            }

            // Bottom row pixels only average last row pixels and top of last row pixels
            else if (row == (height - 1))
            {
                // Left corner
                if (col == 0)
                {
                    // Red
                    int r1 = copy[row][col].rgbtRed;         // Current pixel
                    int r2 = copy[row][col + 1].rgbtRed;     // Pixel on the right
                    int r3 = copy[row - 1][col].rgbtRed;     // Pixel above
                    int r4 = copy[row - 1][col + 1].rgbtRed; // On the right of above pixel
                    // Green
                    int g1 = copy[row][col].rgbtGreen;         // Current pixel
                    int g2 = copy[row][col + 1].rgbtGreen;     // Pixel on the right
                    int g3 = copy[row - 1][col].rgbtGreen;     // Pixel above
                    int g4 = copy[row - 1][col + 1].rgbtGreen; // On the right of above pixel
                    // Blue
                    int b1 = copy[row][col].rgbtBlue;         // Current pixel
                    int b2 = copy[row][col + 1].rgbtBlue;     // Pixel on the right
                    int b3 = copy[row - 1][col].rgbtBlue;     // Pixel above
                    int b4 = copy[row - 1][col + 1].rgbtBlue; // On the right of above pixel

                    // Average pixels
                    int avg_red = (int) round((r1 + r2 + r3 + r4) / 4.0);
                    int avg_green = (int) round((g1 + g2 + g3 + g4) / 4.0);
                    int avg_blue = (int) round((b1 + b2 + b3 + b4) / 4.0);

                    // Update image
                    image[row][col].rgbtRed = avg_red;
                    image[row][col].rgbtGreen = avg_green;
                    image[row][col].rgbtBlue = avg_blue;
                }
                // Right corner
                else if (col == (width - 1))
                {
                    // Red
                    int r1 = copy[row][col].rgbtRed;         // current pixel
                    int r2 = copy[row][col - 1].rgbtRed;     // pixel on the left
                    int r3 = copy[row - 1][col].rgbtRed;     // pixel above
                    int r4 = copy[row - 1][col - 1].rgbtRed; // on the left of above pixel
                    // Green
                    int g1 = copy[row][col].rgbtGreen;         // current pixel
                    int g2 = copy[row][col - 1].rgbtGreen;     // pixel on the left
                    int g3 = copy[row - 1][col].rgbtGreen;     // pixel above
                    int g4 = copy[row - 1][col - 1].rgbtGreen; // on the left of above pixel
                    // Blue
                    int b1 = copy[row][col].rgbtBlue;         // current pixel
                    int b2 = copy[row][col - 1].rgbtBlue;     // pixel on the left
                    int b3 = copy[row - 1][col].rgbtBlue;     // pixel above
                    int b4 = copy[row - 1][col - 1].rgbtBlue; // on the left of above pixel

                    // Average pixels
                    int avg_red = (int) round((r1 + r2 + r3 + r4) / 4.0);
                    int avg_green = (int) round((g1 + g2 + g3 + g4) / 4.0);
                    int avg_blue = (int) round((b1 + b2 + b3 + b4) / 4.0);

                    // Update image
                    image[row][col].rgbtRed = avg_red;
                    image[row][col].rgbtGreen = avg_green;
                    image[row][col].rgbtBlue = avg_blue;
                }
                // Between corners
                else
                {
                    // Red
                    int r1 = copy[row][col].rgbtRed;         // Current pixel
                    int r2 = copy[row][col - 1].rgbtRed;     // Pixel on the left
                    int r3 = copy[row][col + 1].rgbtRed;     // Pixel on the right
                    int r4 = copy[row - 1][col].rgbtRed;     // Pixel above
                    int r5 = copy[row - 1][col - 1].rgbtRed; // On the left of above pixel
                    int r6 = copy[row - 1][col + 1].rgbtRed; // On the right of above pixel
                    // Green
                    int g1 = copy[row][col].rgbtGreen;         // Current pixel
                    int g2 = copy[row][col - 1].rgbtGreen;     // Pixel on the left
                    int g3 = copy[row][col + 1].rgbtGreen;     // Pixel on the right
                    int g4 = copy[row - 1][col].rgbtGreen;     // Pixel above
                    int g5 = copy[row - 1][col - 1].rgbtGreen; // On the left of above pixel
                    int g6 = copy[row - 1][col + 1].rgbtGreen; // On the right of above pixel
                    // Blue
                    int b1 = copy[row][col].rgbtBlue;         // Current pixel
                    int b2 = copy[row][col - 1].rgbtBlue;     // Pixel on the left
                    int b3 = copy[row][col + 1].rgbtBlue;     // Pixel on the right
                    int b4 = copy[row - 1][col].rgbtBlue;     // Pixel above
                    int b5 = copy[row - 1][col - 1].rgbtBlue; // On the left of above pixel
                    int b6 = copy[row - 1][col + 1].rgbtBlue; // On the right of above pixel

                    // Average pixels
                    int avg_red = (int) round((r1 + r2 + r3 + r4 + r5 + r6) / 6.0);
                    int avg_green = (int) round((g1 + g2 + g3 + g4 + g5 + g6) / 6.0);
                    int avg_blue = (int) round((b1 + b2 + b3 + b4 + b5 + b6) / 6.0);

                    // Update image
                    image[row][col].rgbtRed = avg_red;
                    image[row][col].rgbtGreen = avg_green;
                    image[row][col].rgbtBlue = avg_blue;
                }
            }
            // Rows between top and bottom
            else
            {
                // Left columns average only the current and the right columns
                if (col == 0)
                {
                    // Red
                    int r1 = copy[row][col].rgbtRed;         // Current pixel
                    int r2 = copy[row][col + 1].rgbtRed;     // On the right of current pixel
                    int r3 = copy[row - 1][col].rgbtRed;     // Top of current pixel
                    int r4 = copy[row - 1][col + 1].rgbtRed; // Right of Top of current pixel
                    int r5 = copy[row + 1][col].rgbtRed;     // Below of current pixel
                    int r6 = copy[row + 1][col + 1].rgbtRed; // Right of Below of current pixel
                    // Green
                    int g1 = copy[row][col].rgbtGreen;         // Current pixel
                    int g2 = copy[row][col + 1].rgbtGreen;     // On the right of current pixel
                    int g3 = copy[row - 1][col].rgbtGreen;     // Top of current pixel
                    int g4 = copy[row - 1][col + 1].rgbtGreen; // Right of Top of current pixel
                    int g5 = copy[row + 1][col].rgbtGreen;     // Below of current pixel
                    int g6 = copy[row + 1][col + 1].rgbtGreen; // Right of Below of current pixel
                    // Blue
                    int b1 = copy[row][col].rgbtBlue;         // Current pixel
                    int b2 = copy[row][col + 1].rgbtBlue;     // On the right of current pixel
                    int b3 = copy[row - 1][col].rgbtBlue;     // Top of current pixel
                    int b4 = copy[row - 1][col + 1].rgbtBlue; // Right of Top of current pixel
                    int b5 = copy[row + 1][col].rgbtBlue;     // Below of current pixel
                    int b6 = copy[row + 1][col + 1].rgbtBlue; // Right of Below of current pixel

                    // Average pixels
                    int avg_red = (int) round((r1 + r2 + r3 + r4 + r5 + r6) / 6.0);
                    int avg_green = (int) round((g1 + g2 + g3 + g4 + g5 + g6) / 6.0);
                    int avg_blue = (int) round((b1 + b2 + b3 + b4 + b5 + b6) / 6.0);

                    // Update image
                    image[row][col].rgbtRed = avg_red;
                    image[row][col].rgbtGreen = avg_green;
                    image[row][col].rgbtBlue = avg_blue;
                }
                // Right columns average only the current and the left columns
                else if (col == (width - 1))
                {
                    // Red
                    int r1 = copy[row][col].rgbtRed;         // Current pixel
                    int r2 = copy[row][col - 1].rgbtRed;     // On the left of current pixel
                    int r3 = copy[row - 1][col].rgbtRed;     // Top of current pixel
                    int r4 = copy[row - 1][col - 1].rgbtRed; // Left of Top of current pixel
                    int r5 = copy[row + 1][col].rgbtRed;     // Below of current pixel
                    int r6 = copy[row + 1][col - 1].rgbtRed; // Left of Below of current pixel
                    // Green
                    int g1 = copy[row][col].rgbtGreen;         // Current pixel
                    int g2 = copy[row][col - 1].rgbtGreen;     // On the left of current pixel
                    int g3 = copy[row - 1][col].rgbtGreen;     // Top of current pixel
                    int g4 = copy[row - 1][col - 1].rgbtGreen; // Left of Top of current pixel
                    int g5 = copy[row + 1][col].rgbtGreen;     // Below of current pixel
                    int g6 = copy[row + 1][col - 1].rgbtGreen; // Left of Below of current pixel
                    // Blue
                    int b1 = copy[row][col].rgbtBlue;         // Current pixel
                    int b2 = copy[row][col - 1].rgbtBlue;     // On the left of current pixel
                    int b3 = copy[row - 1][col].rgbtBlue;     // Top of current pixel
                    int b4 = copy[row - 1][col - 1].rgbtBlue; // Left of Top of current pixel
                    int b5 = copy[row + 1][col].rgbtBlue;     // Below of current pixel
                    int b6 = copy[row + 1][col - 1].rgbtBlue; // Left of Below of current pixel

                    // Average pixels
                    int avg_red = (int) round((r1 + r2 + r3 + r4 + r5 + r6) / 6.0);
                    int avg_green = (int) round((g1 + g2 + g3 + g4 + g5 + g6) / 6.0);
                    int avg_blue = (int) round((b1 + b2 + b3 + b4 + b5 + b6) / 6.0);

                    // Update image
                    image[row][col].rgbtRed = avg_red;
                    image[row][col].rgbtGreen = avg_green;
                    image[row][col].rgbtBlue = avg_blue;
                }
                // Between columns average 9 adjecent pixels in cluding current pixel
                else
                {
                    // Red
                    int r1 = copy[row][col].rgbtRed;         // Current pixel
                    int r2 = copy[row][col - 1].rgbtRed;     // Left of current pixel
                    int r3 = copy[row][col + 1].rgbtRed;     // Right of current pixel
                    int r4 = copy[row - 1][col - 1].rgbtRed; // Top left of current pixel
                    int r5 = copy[row - 1][col].rgbtRed;     // Top of current pixel
                    int r6 = copy[row - 1][col + 1].rgbtRed; // Top right of currten pixel
                    int r7 = copy[row + 1][col - 1].rgbtRed; // Bottom left of current pixel
                    int r8 = copy[row + 1][col].rgbtRed;     // Bottom of current pixel
                    int r9 = copy[row + 1][col + 1].rgbtRed; // Bottom right of currten pixel
                    // Green
                    int g1 = copy[row][col].rgbtGreen;         // Current pixel
                    int g2 = copy[row][col - 1].rgbtGreen;     // Left of current pixel
                    int g3 = copy[row][col + 1].rgbtGreen;     // Right of current pixel
                    int g4 = copy[row - 1][col - 1].rgbtGreen; // Top left of current pixel
                    int g5 = copy[row - 1][col].rgbtGreen;     // Top of current pixel
                    int g6 = copy[row - 1][col + 1].rgbtGreen; // Top right of currten pixel
                    int g7 = copy[row + 1][col - 1].rgbtGreen; // Bottom left of current pixel
                    int g8 = copy[row + 1][col].rgbtGreen;     // Bottom of current pixel
                    int g9 = copy[row + 1][col + 1].rgbtGreen; // Bottom right of currten pixel
                    // Blue
                    int b1 = copy[row][col].rgbtBlue;         // Current pixel
                    int b2 = copy[row][col - 1].rgbtBlue;     // Left of current pixel
                    int b3 = copy[row][col + 1].rgbtBlue;     // Right of current pixel
                    int b4 = copy[row - 1][col - 1].rgbtBlue; // Top left of current pixel
                    int b5 = copy[row - 1][col].rgbtBlue;     // Top of current pixel
                    int b6 = copy[row - 1][col + 1].rgbtBlue; // Top right of currten pixel
                    int b7 = copy[row + 1][col - 1].rgbtBlue; // Bottom left of current pixel
                    int b8 = copy[row + 1][col].rgbtBlue;     // Bottom of current pixel
                    int b9 = copy[row + 1][col + 1].rgbtBlue; // Bottom right of currten pixel

                    // Average pixels
                    int avg_red = (int) round((r1 + r2 + r3 + r4 + r5 + r6 + r7 + r8 + r9) / 9.0);
                    int avg_green = (int) round((g1 + g2 + g3 + g4 + g5 + g6 + g7 + g8 + g9) / 9.0);
                    int avg_blue = (int) round((b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8 + b9) / 9.0);

                    // Update image
                    image[row][col].rgbtRed = avg_red;
                    image[row][col].rgbtGreen = avg_green;
                    image[row][col].rgbtBlue = avg_blue;
                }
            }
        }
    }


    return;
}
