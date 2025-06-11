#include <cs50.h>
#include <stdio.h>

void bubble_sort(int arr[], int n);

int main(void)
{
    int numbers[] = {5, 2, 1, 3, 6, 4};
    int n = 6;

    bubble_sort(numbers, n);

    for (int i = 0; i < n; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
