// Implements a dictionary's functionality
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

//trie node
typedef struct node
{
    bool is_word;
    struct node *children[27];
} node;

node *root;

int word_count = 0;

int get_index(char c);
node *create_init_node();
bool unload_dict(node *node_ptr);

// Returns true if word is in dictionary else return false
bool check(const char *word)
{
    node *node_ptr = root; //pointer to root node

    for (int i = 0, len = strlen(word); i <= len; i++)
    {
        if (word[i] == '\0')
        {
            if (node_ptr->is_word == true)
            {
              return true;
            }
            else
            {
              return false;
            }
        }

        int index = get_index(word[i]);
        if (node_ptr->children[index] == NULL) //word is misspelled
        {
          return false;
        }
        else
        {
            //if not NULL, move to next letter
            node_ptr = node_ptr->children[index];
        }
    }
    return true;
}

// Loads dictionary into memory, returning true if successful else return false
bool load(const char *dictionary)
{
    FILE *dict_ptr = fopen(dictionary, "r");
    if (dict_ptr == NULL)
    {
        fprintf(stderr, "File doesn't exist\n");
        return false;
    }

    //Initialize c to get a char from dictionary and check until we reach
    root = create_init_node();

    int index;
    node *node_ptr = root;
    //for every word iterate through the trie
    for (char c = fgetc(dict_ptr); c != EOF; c = fgetc(dict_ptr))
    {
        //if the letter is not a newline char then load it to our trie
        //each element in children corresponds to a different letter
        if (c != '\n')
        {
            index = get_index(c);

            if (node_ptr->children[index] == NULL)
            {
                node_ptr->children[index] = create_init_node();
            }

            node_ptr = node_ptr->children[index];

        }

        else
        {
            // reach the end of the word
            node_ptr->is_word = true;
            word_count++;
            //go back to beginning
            node_ptr = root;
        }
    }
    fclose(dict_ptr);
    return true;
}

//Returns entered character's index
int get_index(char c)
{
    //last index is '\''
    if (c == '\'')
    {
        return 26;
    }
    else if (c >= 'a' && c <= 'z')
    {
        return c - 'a';
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return c - 'A';
    }
    return -1;
}
//Returns a pointer to a node with initial values
node *create_init_node()
{
    node *node_ptr = malloc(sizeof(node));
    node_ptr->is_word = false;

    for (int i = 0; i < 27; i++) //including \'
    {
        node_ptr->children[i] = NULL;
    }
    return node_ptr;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if (unload_dict(root))
    {
      return true;
    }
    return false;
}
bool unload_dict(node *node_ptr)
{
    //free all pointers in children
    for (int i = 0; i < 27; i++)
    {
        if (node_ptr->children[i] != NULL)
        {
            unload_dict(node_ptr->children[i]);
        }
    }
    //After emptied/NULL everything
    free(node_ptr);
    return true;
}
