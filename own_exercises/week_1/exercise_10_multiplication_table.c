#include <cs50.h>
#include <stdio.h>

void multiplication_table(int number, int i)
{
    for (i = 1; i < 11; i++)
    {
        int result = number * i;
        printf("%d x %d = %d\n", number, i, result);
    }
}

int main(void)
{
    int number = get_int("Send a number: ");
    int i;

    printf("The multiplication table of this number is:\n");
    multiplication_table(number, i);

    return 0;
}
