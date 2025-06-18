#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    char number[20];
} person;

int main(void)
{
    person people[2];
    strcpy(people[0].name, "Alice");
    strcpy(people[0].number, "+1-555-1234");

    strcpy(people[1].name, "Bob");
    strcpy(people[1].number, "+1-555-5678");

    for (int i = 0; i < 2; i++)
    {
        printf("%s: %s\n", people[i].name, people[i].number);
    }
}
