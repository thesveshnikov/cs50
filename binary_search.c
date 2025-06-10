#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {0, 2, 4, 5, 6, 7, 8};
    int n = get_int("Number: ");

    int left = 0;
    int right = 6;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (numbers[mid] == n)
        {
            printf("Found\n");
            return 0;
        }
        else if (numbers[mid] < n)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    printf("Not found\n");
    return 1;
}
