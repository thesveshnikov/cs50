#include "trie.h"
#include <ctype.h>
#include <string.h>

node *create_node()
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) return NULL;

    new_node->is_word = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        new_node->children[i] = NULL;

    return new_node;
}

int char_to_index(char c)
{
    if (c == '\'') return 26;
    return tolower(c) - 'a';
}

void free_trie(node *root)
{
    if (root == NULL) return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        free_trie(root->children[i]);

    free(root);
}
