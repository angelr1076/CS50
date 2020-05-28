// TODO
// * Open Dictionary file
// * Read string from file one at a time
// * Create a new node for each word
// * Hash word to obtain a hash value
// * Insert node into hash table at that location
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 30;

//Number of words on dictionary
int trav_count = -1;

//Check if dictionary is loaded
bool is_loaded = false;

// Hash table
node *table[N] = {NULL};

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Case insensitive
    // Hash word to obtain a hash value
    // Access linked list at that index in the hash table
    unsigned int k = hash(word);

    node *traverse = table[k];

    while (traverse != NULL)
    {
        // Traverse linked list, looking for the word (strcasecmp), ex. cursor = cursor->next;
        if ((strcasecmp(word, traverse->word)) == 0)
        {
            return true;
        }
        else
        {
            traverse = traverse->next;
        }
    }
    return false;
}

// Hashes word to a number
// Input: word, with alphabetical characters and (possibly) apostrophes
// Outputs a number corresponding to which "bucket" to store the word in, between 0 and N - 1
unsigned int hash(const char *word)
{
    // assign a number to the first char of buffer from 0-25 in the alphabet
    if ((isalpha(word[0]) > 0))
    {
        return tolower(word[0]) - 'a';
    }
    else
    {
        return 26;
    }
}


// 1st task
// Loads dictionary into memory, returning true if successful else if false
bool load(const char *dictionary)
{
    // TODO
    // create a FILE pointer and fopen() to start the stream
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        is_loaded = false;
        return false;
    }

    char curr_word[LENGTH + 1];
    char curr;

    do
    {
        curr = fscanf(file, "%s", curr_word);
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            is_loaded = false;
            return false;
        }

        strcpy(n->word, curr_word);
        n->next = NULL;
        unsigned int i = hash(curr_word);

        if (table[i] == NULL)
        {
            table[i] = n;
        }
        else
        {
            node *pointer = table[i];

            while (true)
            {
                if (pointer->next == NULL)
                {
                    pointer->next = n;
                    break;
                }
                pointer = pointer->next;
            }
        }

        trav_count++;

    }
    while (curr != EOF);

    fclose(file);
    is_loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{

        return trav_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
    // TODO
    // free(temp);
{
    for (int i = 0; i < N; i++)
    {
        // cursor variable is an additional variable tracking where we are in the linked list
        node *cursor = table[i];

        while (cursor != NULL)
        {
            // tmp variable remains one step behind cursor in order to remove the current node while cursor moves to the next node in the linked list
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    is_loaded = false;
    return true;
}