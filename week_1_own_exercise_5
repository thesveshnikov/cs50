#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float number_1 = get_float("Send me a number: ");
    float number_2 = get_float("Send me other number: ");
    char operator = get_char("Send me the operator: ");

    float result;

    switch (operator)
    {
        case '+':
            result = number_1 + number_2;
            printf("The result is %.2f\n", result);
            break;
        case '-':
            result = number_1 - number_2;
            printf("The result is %.2f\n", result);
            break;
        case '*':
        case 'x':
            result = number_1 * number_2;
            printf("The result is %.2f\n", result);
            break;
        case '/':
            if (number_2 != 0)
            {
                result = number_1 / number_2;
                printf("The result is %.2f\n", result);
            }
            else
            {
                printf("Cannot divide by zero.\n");
            }
            break;
        default:
            printf("Invalid operation\n");
    }

    return 0;
}
