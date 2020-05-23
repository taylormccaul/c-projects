// Implements a dictionary's functionality

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(void/*const char *dictionary*/)
{
    //return false;
    char letters[27];

    for (int i = 0; i < 26; i++) {
        letters[i] = (char)i+97;
        printf("%c", letters[i]);
    }

    //free(letters);
    return true;
    /*node *list = NULL;
    int counter = 0;

    node *n = malloc(sizeof(dictionary));
    if (n == NULL) {
        return 1;
    }

    n->word = dictionary;
    n->next = NULL;
    list = n;

    n = malloc(sizeof(dictionary));
    if (n == NULL) {
        return 1;
    }

    n->word = dictionary;
    n->next = NULL;
    list = n;

    while (list != NULL) {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }*/
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}

int main(void) {
    //printf("%c", (char)1+97);
    load();
    return 0;
}
