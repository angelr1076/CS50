#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        //Continue to ask the user for a number between 1 and 8
        height = get_int("Height: ");
    }
    //ask the user for height until they enter a valid number between 1 and 8.
    while (height < 1 || height > 8);

    //create a 2-dimensional loop and print hashes or spaces depending on the value of i + j combined
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (i + j < height - 1)
                printf(" ");
            else
                printf("#");
        }
        //at the end of each line, return
        printf("\n");
    }
}
