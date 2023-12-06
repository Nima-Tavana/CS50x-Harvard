// Implements a dictionary's functionality
#include "dictionary.h"
#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

int dictionary_lenght = 0;

// Choose number of buckets in hash table
const unsigned int N = 99888;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashed = hash(word);
    node *the_next = table[hashed];

    while (!(the_next == NULL))
    {
        if (strcasecmp(word, the_next->word) == 0)
        {
            return true;
        }
        the_next = the_next->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int result = 0;

    for (int p = 0; p < strlen(word); p++)
    {
        int letter = tolower(word[p]);
        result = result + letter;
    }
    return result % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dictionary_ptr = fopen(dictionary, "r");
    if (!(dictionary_ptr != NULL))
    {
        return false;
    }

    char the_next_word[LENGTH + 1];

    while (!(fscanf(dictionary_ptr, "%s", the_next_word) == EOF))
    {
        node *the_next = malloc(sizeof(node));
        if (!(the_next != NULL))
        {
            return false;
        }

        strcpy(the_next->word, the_next_word);
        int after_being_hashed = hash(the_next_word);

        the_next->next = table[after_being_hashed];
        table[after_being_hashed] = the_next;
        // if found the size of dictionary should be plused by one
        dictionary_lenght = dictionary_lenght + 1;
    }
    fclose(dictionary_ptr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // returnin the number of words available in dictionary
    return dictionary_lenght;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // freeing the dictionary from the memory
    for (int p = 0; p < N; p++)
    {
        node *the_next = table[p];

        while (!(the_next == NULL))
        {
            node *temp = the_next;
            the_next = the_next->next;
            free(temp);
        }
        if (the_next == NULL)
        {
            if (p == N - 1)
            {
                return true;
            }
        }
    }
    return false;
}
