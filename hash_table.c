#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct node
{
    char *key;
    char *value;
    struct node *next;
}
node;

node *hash_table[TABLE_SIZE];

unsigned int hash(char *key);
void insert(char *key, char *value);
char *search(char *key);

int main(void)
{
    insert("CS50", "Introduction to Computer Science");
    insert("CS51", "Introduction to Computer Science II");
    insert("CS120", "Data Structures");

    printf("%s\n", search("CS50"));
    printf("%s\n", search("CS51"));
    printf("%s\n", search("CS120"));
    printf("%s\n", search("CS200"));

    return 0;
}

unsigned int hash(char *key)
{
    unsigned int hash_value = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        hash_value = (hash_value * 31 + key[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void insert(char *key, char *value)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return;
    }
    n->key = strdup(key);
    n->value = strdup(value);
    n->next = NULL;

    unsigned int index = hash(key);
    if (hash_table[index] == NULL)
    {
        hash_table[index] = n;
    }
    else
    {
        n->next = hash_table[index];
        hash_table[index] = n;
    }
}

char *search(char *key)
{
    unsigned int index = hash(key);
    node *tmp = hash_table[index];
    while (tmp != NULL)
    {
        if (strcmp(tmp->key, key) == 0)
        {
            return tmp->value;
        }
        tmp = tmp->next;
    }
    return NULL;
}
