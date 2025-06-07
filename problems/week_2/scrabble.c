#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compute_score(string word);

int main(void)
{
    string word = get_string("Palavra: ");
    printf("%i\n", compute_score(word));
}

int compute_score(string word)
{
    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        char c = toupper(word[i]);
