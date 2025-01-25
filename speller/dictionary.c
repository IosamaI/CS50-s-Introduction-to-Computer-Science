#define _GNU_SOURCE // Enables POSIX functions like strcasecmp
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

#define N 100000 // A larger prime number to reduce collisions in the hash table

// Define a struct for each node in the hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Hash table
node *table[N];

// Counter for number of words loaded
unsigned int word_count = 0;

// Hash function to hash a word to a number based on its characters
unsigned int hash(const char *word)
{
    unsigned long hash_value = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash_value = (hash_value * 31 + tolower(word[i])) % N; // use 31 for better distribution
    }
    return hash_value % N;
}

// Load dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%45s", word) != EOF)
    { // Read each word
        // Allocate a new node
        node *new_node = malloc(sizeof(node));
        if (!new_node)
        {
            fclose(file);
            return false;
        }

        // Copy word into node and hash it
        strcpy(new_node->word, word);
        int index = hash(word);

        // Insert node into hash table (at the start of the linked list)
        new_node->next = table[index];
        table[index] = new_node;

        // Increase word count
        word_count++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    node *cursor = table[index];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
