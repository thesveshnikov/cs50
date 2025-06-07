#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool is_unique(string key);
bool is_valid_key(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Uso: ./substitution chave\n");
        return 1;
    }

    string key = argv[1];
    if (!is_valid_key(key))
    {
        printf("Chave inválida.\n");
        return 1;
    }

    if (!is_unique(key))
    {
        printf("Chave deve conter letras únicas.\n");
        return 1;
    }

    string plaintext = get_string("Texto: ");
    printf("Texto cifrado: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            char base = islower(c) ? 'a' : 'A';
            printf("%c", islower(c) ? tolower(key[c - base]) : toupper(key[c - base]));
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}

bool is_valid_key(string key)
{
    if (strlen(key) != 26)
        return false;

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
            return false;
    }
    return true;
}

bool is_unique(string key)
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
                return false;
        }
    }

::contentReference[oaicite:3]{index=3}
 
