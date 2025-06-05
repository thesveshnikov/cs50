#include <stdio.h>

int main()
{
    // Declare an array
    int numbers[5];
    numbers[0] = 1;
    
    // Populate an array
    for (int i = 1; i < 5; i++)
    {
        numbers[i] = numbers[i - 1] * 2;
    }
    
    // Print out the values one by one
    for (int i = 0; i < 5; i++)
    {
        printf("%i\n", numbers[i]);
    }
}
