#include <stdio.h>
#include <cs50.h>

#define PI 3.14159

int main(void)
{
    float radius = get_float("Enter the radius: ");
    float area = PI * radius * radius;
    printf("Area: %f\n", area);
    return 0;
}
