#include <stdio.h>
#include <cs50.h>

void print_row(int bricks);

int main(void)
{
    // Prompt user for input
    int height = get_int("What is the height of the pyramid? ");
    
    // Print a pyramid of that height
    print_row(height);
}

void print_row(int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
