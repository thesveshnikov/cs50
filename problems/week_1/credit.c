#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool check_luhn(long number);
int get_length(long number);
int get_start_digits(long number, int length);

int main(void)
{
    long number = get_long("Number: ");

    int length = get_length(number);
    int start = get_start_digits(number, length);

    if (check_luhn(number))
    {
        if ((start == 34 || start == 37) && length == 15)
        {
            printf("AMEX\n");
        }
        else if (start >= 51 && start <= 55 && length == 16)
        {
            printf("MASTERCARD\n");
        }
        else if ((start / 10 == 4 || start == 4) && (length == 13 || length == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

bool check_luhn(long number)
{
    int sum = 0;
    bool alternate = false;

    while (number > 0)
    {
        int digit = number % 10;
        if (alternate)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }
        sum += digit;
        alternate = !alternate;
        number /= 10;
    }

    return sum % 10 == 0;
}

int get_length(long number)
{
    int length = 0;
    while (number != 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

int get_start_digits(long number, int length)
{
    while (length > 2)
    {
        number /= 10;
        length--;
    }
    return (int) number;
}
