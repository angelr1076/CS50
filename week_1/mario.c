#include <cs50.h>
#include <math.h>
#include <stdio.h>

void hashes(int num);
void spaces(int num);

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
        spaces(count_spaces);
        hashes(count_hashes);
        printf("  ");
        hashes(count_hashes);
        printf("\n");
        count_spaces--;
        count_hashes++;
    }
}

void hashes(int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("#");
    }
}

void spaces(int num)
{
    for (int i = 0; i < num; i++)
    {
        printf(" ");
    }
}
