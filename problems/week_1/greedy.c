#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    int cents = round(dollars * 100);
    int coins = 0;

    int denominations[] = {25, 10, 5, 1};

    for (int i = 0; i < 4; i++)
    {
        while (cents >= denominations[i])
        {
            cents -= denominations[i];
            coins++;
        }
    }

    printf("%i\n", coins);
}
