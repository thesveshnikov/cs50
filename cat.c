#include <cs50.h>
#include <stdio.h>

void meow(void);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number: ");
    }
    while (n < 1);
    meow(n);
}

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
       printf("meow\n");
    }
}
