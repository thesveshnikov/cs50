#include <stdio.h>

int main(void)
{
    // Never change n
    const int n = 3;
    
    // Print n rows
    for (int i = 0; i < n; i++)
    {
        print_row(n);
    }
}

void print_row(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
