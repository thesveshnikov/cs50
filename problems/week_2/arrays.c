#include <stdio.h>

int main()
{
    // Declare an array
    int numbers[5];
    
    // Populate an array
    numbers[0] = 1;
    numbers[1] = numbers[0] * 2;
    numbers[2] = numbers[1] * 2;
    numbers[3] = numbers[2] * 2;
    numbers[4] = numbers[3] * 2;
    
    // int numbers[5] = {1, 2, 4, 8, 16};
    
    // Print out the values one by one
    for (int i = 0; i < 5; i++)
    {
        printf("%i\n", numbers[i]);
    }
}
