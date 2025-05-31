#include <cs50.h>
#include <stdio.h>

int get_option(void)
{
    int op = get_int("Which expression do you want to apply?\n1. Sum\n2. Subtraction\n3. Multiplication\n4. Division\n");
    return op;
}

int main(void)
{
    double number_1 = get_double("Enter a number: ");
    double number_2 = get_double("Enter another number: ");
    double result;
    int op = get_option();

    if (op == 1)
    {
        result = number_1 + number_2;
        printf("The result is %.2lf\n", result);
    }
    else if (op == 2)
    {
        result = number_1 - number_2;
        printf("The result is %.2lf\n", result);
    }
    else if (op == 3)
    {
        result = number_1 * number_2;
        printf("The result is %.2lf\n", result);
    }
    else if (op == 4)
    {
        if (number_2 == 0)
        {
            printf("Error: Division by zero is not allowed.\n");
        }
        else
        {
            result = number_1 / number_2;
            printf("The result is %.2lf\n", result);
        }
    }
    else
    {
        printf("Invalid option selected.\n");
    }

    return 0;
}
