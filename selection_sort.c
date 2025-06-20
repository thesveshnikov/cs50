#include <cs50.h>
#include <stdio.h>

void selection_sort(int arr[], int n);

int main(void)
{
    int numbers[] = {5, 2, 1, 3, 6, 4};
    int n = 6;

    selection_sort(numbers, n);

    for (int i = 0; i < n; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}
