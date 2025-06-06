#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get user's input
    string text = get_string("Input: ");
    
    // Iterate through each element in the string
    for (int i = 0; i < strlen(text); i++)
    {
        printf("%c", text[i]);
    }
        // check if it is alphabetical
    
    // Print out yes or no
}
