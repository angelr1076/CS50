#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include <ctype.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Each pixels rgb values need to be the same
    for (int height_i = 0; height_i < height; height_i++)
    {
        for (int width_i = 0; width_i < width; width_i++)
        {
            // Calc the average of the rgb for each pixel
            // Need integer values, round to the nearest integer
            int rgbt_average = round((image[height_i][width_i].rgbtBlue + image[height_i][width_i].rgbtGreen + image[height_i][width_i].rgbtRed) / 3.0);

            // Change each rgbt value to its average value
            image[height_i][width_i].rgbtBlue = rgbt_average;
            image[height_i][width_i].rgbtGreen = rgbt_average;
            image[height_i][width_i].rgbtRed = rgbt_average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int height_i = 0; height_i < height; height_i++)
    {
        for (int width_i = 0; width_i < width; width_i++)
        {
            // Get pixel color values
            int originalBlue = image[height_i][width_i].rgbtBlue;
            int originalGreen = image[height_i][width_i].rgbtGreen;
            int originalRed = image[height_i][width_i].rgbtRed;

            // Take each pixel and convert it to the sepia equivalent with the formula, and round the number if it's not an integer
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);

            // Values should be capped at 255
            // Convert each pixel to its sepia value
            image[height_i][width_i].rgbtBlue = sepiaBlue > 255 ? sepiaBlue = 255 : sepiaBlue;
            image[height_i][width_i].rgbtGreen = sepiaGreen > 255 ? sepiaGreen = 255 : sepiaGreen;
            image[height_i][width_i].rgbtRed = sepiaRed > 255 ? sepiaRed = 255 : sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Each image is just a 2-dim array
    // Rows stay in the same order, but the pixels in the row switch places
    // Take each row and apply the same filter to that row
    // If there is an even number of pixels, there is no middle so they all switch
    // swap pixels on horizontally opposite sides

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Box blur - compute the new value of the pixels by taking the average of the 9 pixels in a grid
    // We won't always have 9 pixels, so we'll average 6 color values within one row and one column
    // You may only need 4 for a corner pixel

    return;
}


// To get a row, use image[0], image[1] etc.
// To get the last row, use image[height - 1]

// image[0] is the first row, image [0][0] is the first pixel, image[0][1] is the second and so on
// How do we modify the pixel, it's just a struct as so:
// image[2][3].rgbtRed = 0;
// image[2][3].rgbtGreen = 0;

