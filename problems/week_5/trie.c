#include <stdbool.h>
#include <stdlib.h>

#define ALPHABET_SIZE 27 // a-z + apostrophe

typedef struct node
{
    bool is_word;
    struct node *children[ALPHABET_SIZE];
} node;

node *create_node();
int char_to_index(char c);
void free_trie(node *root);
