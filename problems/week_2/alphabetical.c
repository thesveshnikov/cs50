#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Get user's input
    if (argc != 2)
    {
        printf("Please provide a word.\n");
        return 1;
    }
    
    string text = argv[1];
    
    // Iterate through each element in the string
    for (int i = 1; i < strlen(text); i++)
    {
        if (text[i] < text[i - 1])
        {
            printf("No\n");
            return 0;
        }
    }
    // Print out yes
    printf("Yes\n");
}
