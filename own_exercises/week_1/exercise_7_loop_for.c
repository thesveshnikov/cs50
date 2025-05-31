#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int sum = 0;

    printf("hello world\n");

    int n = get_int("Enter how many numbers to sum: ");

    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }

    printf("The result of sum is: %d\n", sum);

    return 0;
}
