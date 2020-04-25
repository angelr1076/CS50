#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include <ctype.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int height_i = 0; height_i < height; height_i++)
    {
        for (int width_j = 0; width_j < width; width_j++)
        {
            // Calc the average of the rgb for each pixel. Each pixels rgb values need to be the same
            // Need integer values, round to the nearest integer
            int rgbt_average = round((image[height_i][width_j].rgbtBlue + image[height_i][width_j].rgbtGreen + image[height_i][width_j].rgbtRed) / 3.0);

            // Change each rgbt value to its average value
            image[height_i][width_j].rgbtBlue = rgbt_average;
            image[height_i][width_j].rgbtGreen = rgbt_average;
            image[height_i][width_j].rgbtRed = rgbt_average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int height_i = 0; height_i < height; height_i++)
    {
        for (int width_j = 0; width_j < width; width_j++)
        {
            // Get pixel color values
            int originalBlue = image[height_i][width_j].rgbtBlue;
            int originalGreen = image[height_i][width_j].rgbtGreen;
            int originalRed = image[height_i][width_j].rgbtRed;

            // Take each pixel and convert it to the sepia equivalent with the formula, and round the number if it's not an integer
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);

            // Values should be capped at 255; Convert each pixel to its sepia value
            image[height_i][width_j].rgbtBlue = sepiaBlue > 255 ? sepiaBlue = 255 : sepiaBlue;
            image[height_i][width_j].rgbtGreen = sepiaGreen > 255 ? sepiaGreen = 255 : sepiaGreen;
            image[height_i][width_j].rgbtRed = sepiaRed > 255 ? sepiaRed = 255 : sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int height_i = 0; height_i < height; height_i++)
    {
        for (int width_j = 0; width_j < width / 2; width_j++)
        {
            // Make a copy of RGBTRIPLE image
            RGBTRIPLE copy_image = image[height_i][width_j];
            // Swap the first pixel with the last and work from the end to the middle
            image[height_i][width_j] = image[height_i][width - 1 - width_j];
            image[height_i][width - 1 - width_j] = copy_image;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Create new array
    RGBTRIPLE copy_image[height][width];

    //Make a copy, pixel for pixel inside of a 2-dimensional array
    for (int height_i = 0; height_i < height; height_i++)
    {
        for (int width_j = 0; width_j < width; width_j++)
        {
            //make copy in array
            copy_image[height_i][width_j] = image[height_i][width_j];
        }
    }

    for (int height_i = 0; height_i < height; height_i++)
    {
        for (int width_j = 0; width_j < width; width_j++)
        {
            //Create counter and int to store each of the connected surrounding colors
            float counter = 0;
            float newRed = 0;
            float newGreen = 0;
            float newBlue = 0;

            //Check for the surrounding pixels connected to copy_image[i][j] by no more than 1 pixel
            for (int height_k = -1; height_k < 2; height_k++)
            {
                for (int width_l = -1; width_l < 2; width_l++)
                {
                    //A pixel exists if it is greater than 0 and less than height or width
                    if (height_i + height_k >= 0 && height_i + height_k < height && width_j + width_l >= 0 && width_j + width_l < width)
                    {
                        //Store the value in the new color int and increase the counter to get a divisor for the avg
                        newRed += copy_image[height_i + height_k][width_j + width_l].rgbtRed;
                        newGreen += copy_image[height_i + height_k][width_j + width_l].rgbtGreen;
                        newBlue += copy_image[height_i + height_k][width_j + width_l].rgbtBlue;
                        counter++;
                    }
                }
            }
            //Average color value of connected surrounding pixels and assign it to image round the temp and divide by counter
            image[height_i][width_j].rgbtRed = round(newRed / counter);
            image[height_i][width_j].rgbtGreen = round(newGreen / counter);
            image[height_i][width_j].rgbtBlue = round(newBlue / counter);
        }
    }
    return;
}