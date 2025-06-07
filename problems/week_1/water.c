#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int minutes = get_int("Minutes: ");
    int bottles = minutes * 12;
    printf("Bottles: %i\n", bottles);
}
