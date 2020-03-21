#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (argc == 2)
    {
        //  Convert that command-line argument from a string to an int
        int key = atoi(argv[1]);
        // Iterate over the char *argv[] (second argument) to make sure all characters are digits
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("You can only enter a number or numbers for your second command line argument.\n");
                return 1;
            }
        }

        // Prompt user for plaintext
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        // Iterate over each character of the plaintext:
        for (int i = 0; i < strlen(plaintext); i++)
        {
            // If it is an uppercase letter, rotate it, preserving case, then print out the rotated character, A-Z (65 - 90)
            // ci (ith character of the cipher text) = p is plaintext (unencrypted), pi is the ith character in p + k (secret key) % 26 remainder when dividing by numbers in the alphabet
            // We can directly apply it to our formula because ASCII starts at 65, ex. A or 90, ex. Z
            if (isupper(plaintext[i]))
            {
                char letter = (((plaintext[i] - 'A') + key) % 26) + 'A';
                printf("%c", letter);
            }
            // If it is a lowercase letter, rotate it, preserving case, then print out the rotated character, a - z (97 - 122)
            else if (islower(plaintext[i]))
            {
                char letter = (((plaintext[i] - 'a') + key) % 26) + 'a';
                printf("%c", letter);
            }
            else
            {
                // If it isn't uppercase or lowercase, it must be a non-alphabetic character so print out the character as is
                char letter = plaintext[i];
                printf("%c", letter);
            }
        }
        // Print a new line
        printf("\n");
    }
}
