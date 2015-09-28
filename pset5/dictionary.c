/****************************************************************************
 * dictionary.c
 *
 * Lisa Carson
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <cs50.h>

#include <stdbool.h>

#include "dictionary.h"

#include <ctype.h>

#include <stdlib.h>

#include <stdio.h>

#include <string.h>

node* hashtable[26];
int hashed;
int wordcount = 0;

int hash_function(char* key)
{
    int hash = toupper(key[0]) - 'A';
    return hash;
}
int hashed;


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    
    int n = strlen(word);
    char lower[n + 1];
    strcpy(lower, word);
    
    for(int i = 0; i < n; i++)
    {
        
        lower[i] = tolower(word[i]);
    }

    int checking = hash_function(lower);  
    
    
    
    node* cursor = hashtable[checking];
    
    
    while (cursor != NULL)
    {
        if (strcmp(cursor->word, lower) == 0)
        {
            return true;
        }
        
        cursor = cursor->next;
        
    }
      
        
    return false;
    
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */

bool load(const char* dictionary)
{
    // TODO
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return 1;
    }
    
    char word[46] = {'\0'};
    
   
        
       
        
        
        
    while (fscanf(file, "%s", word) == 1)
    {
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return 1;
        }
           

        strcpy(new_node->word, word);
           
        if (new_node->word == NULL)
            return 1;
    
        hashed = hash_function(new_node->word);
        
        if (hashtable[hashed] == NULL)
        {
            new_node->next = NULL;
            hashtable[hashed] = new_node;
            wordcount++;
        }
        else
        {
            new_node->next = hashtable[hashed];
            hashtable[hashed] = new_node;                                    
            wordcount++;
        }
    }
        
        
   
    fclose(file);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
 
unsigned int size(void)
{
    // TODO
    return wordcount;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    for (int i = 0; i < 26; i++)
    {
        node* cursor = hashtable[i];
        
        while (cursor != NULL)
        {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
    return true;
}
