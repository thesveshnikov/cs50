#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 1; i <= height; i++)
    {
        // Espaços à esquerda
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }

        // Blocos à esquerda
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        // Espaço do meio
        printf("  ");

        // Blocos à direita
        for (int l = 0; l < i; l++)
        {
            printf("#");
        }

        printf("\n");
    }
}
