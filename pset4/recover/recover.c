#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // If your program is not executed with exactly one command-line argument, it should remind the user of correct usage, and main should return 1.
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Create an input pointer
    FILE *input_file = fopen(argv[1], "r");
    // If the forensic image cannot be opened for reading, program should inform the user, and main should return 2.
    while (!input_file || input_file == NULL)
    {
        fprintf(stderr, "File is either an invalid type, or it cannot be opened\n");
        return 2;
    }

    // img output pointer initially set to NULL
    FILE *img_output = NULL;
    // Create a 512 BYTE block for memory
    unsigned char byte[512];
    // filename needs to be xxx.jpg length + 1
    char filename[8];
    // Set a counter to add num to image name and increment in loop to automate naming
    int jpg_count = 0;
    // Initiate bool to false outside of the loop, this will be set to true at the end of each image
    bool img_end = false;

    // Read 512 bytes into a buffer of filename "file" 1 byte at a time
    while (fread(byte, 512, 1, input_file) == 1) // returns 1 if true
    {
        // Look at jpg signature in the first four bytes for a jpeg file
        if (byte[0] == 0xff && byte[1] == 0xd8 && byte[2] == 0xff && (byte[3] & 0xf0) == 0xe0)
        {
            // Close img if end to open next jpg
            if (img_end)
            {
                fclose(img_output);
            }
            // Start of a new jpg
            else
            {
                // Set end to true then open output below and name it based on jpg_count
                img_end = true;
            }
            // name the img based on the counter ###.jpg starting at 000.jpg
            sprintf(filename, "%03i.jpg", jpg_count);
            // Open a new jpg file
            img_output = fopen(filename, "w");
            // Add to counter each time an image is written to output
            jpg_count++;
        }
        if (img_end)
        {
            // fwrite (data, size, number, outptr);
            fwrite(byte, 512, 1, img_output);
        }
    }
    // Close all files and return success from main
    fclose(input_file);
    fclose(img_output);
    return 0;
}