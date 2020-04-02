#include <cs50.h>
#include <math.h>
#include <stdio.h>

int print_hashes(int num);
int print_spaces(int num);

int main(void)
{
    int height, count_spaces, count_hashes;

    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    count_spaces = height - 1;
    count_hashes = 1;

    for (int i = 0; i < height; i++)
    {
        print_spaces(count_spaces);
        print_hashes(count_hashes);
        printf("  ");
        print_hashes(count_hashes);
        printf("\n");
        count_spaces--;
        count_hashes++;
    }
}

int print_hashes(int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("#");
    }
}

int print_spaces(int num)
{
    for (int i = 0; i < num; i++)
    {
        printf(" ");
    }
}
