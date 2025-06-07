#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int compute_grade(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Texto: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int grade = compute_grade(letters, words, sentences);

    if (grade < 1)
        printf("Antes da 1ª série\n");
    else if (grade >= 16)
        printf("12ª série ou superior\n");
    else
        printf("Série %i\n", grade);
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
            count++;
    }
    return count;
}

int count_words(string text)
{
    int count = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
            count++;
    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
            count++;
    }
    return count;
}

int compute_grade(int letters, int words, int sentences)
{
    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return (int)index;
}
