#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[]) {
    if (argc != 3) {
        printf("Provide two numbers as arguments.\n");
        printf("Usage: %s <number1> <number2>\n", argv[0]);
        return 1;
    }

    int number_1 = atoi(argv[1]);
    int number_2 = atoi(argv[2]);

    int sum = number_1 + number_2;

    printf("The sum of %d and %d is %d.\n", number_1, number_2, sum);

    return 0;
}
