#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int get_letters(string text);
int get_words(string text);
int get_sentences(string text);


//main function
int main()
{
    string text = get_string("Text: ");

    //pass arguments to helper functions
    int letters = get_letters(text);
    int words = get_words(text);
    int sentences = get_sentences(text);

    // Calculate the letters and sentences per 100 words of the text with floats once helpers are done 100 * the variable / words
    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;

    //Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int final_grade = round(index);

    if (final_grade < 1)
    {
        //Don't add the variable when calling Before Grade 1, otherwise, the number may be well below 1
        printf("Before Grade 1\n");
    }
    else if (final_grade >= 16)
    {
        //Don't add the variable when calling 16+, otherwise, you will return the exact number which in this case, you don't want to return
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", final_grade);
    }
}

//add helper functions
// count letters
int get_letters(string text)
{
    int count = 0;

    for (int i = 0; i <= strlen(text); i++)
    {
        if (text[i] >= 'A' && text[i] <= 'z')
        {
            count++;
        }
    }
    return count;
}

// //count words
int get_words(string text)
{
    //the first word will always be skipped in the count, so start at 1
    int count = 1;

    for (int i = 0; i <= strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count;
}
// //count sentences
int get_sentences(string text)
{
    int count = 0;

    for (int i = 0; i <= strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}