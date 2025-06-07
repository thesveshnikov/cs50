#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Uso: ./caesar chave\n");
        return 1;
    }

    int k = atoi(argv[1]);
    if (k < 0)
    {
        printf("Chave deve ser um número inteiro não negativo.\n");
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
            printf("%c", (c - base + k) % 26 + base);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}
