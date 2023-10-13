#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
     // printf("%d letters\n",count_letters(text));
     // printf("%d words\n",count_words(text));
     // printf("%d sentences\n",count_sentences(text));

    float W = count_words(text);
    float L = count_letters(text) / W * 100;
    float S = count_sentences(text) / W * 100;
    float index =  0.0588 * L - 0.296 * S - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >=16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int)round(index));
    }
}

int count_letters(string text)
{
    int sum = 0;
    for (int i = 0 ,  length = strlen(text); i < length; i++)
    {
        if (isupper(text[i]))
        {
            sum++;
        }
        else if (islower(text[i]))
        {
            sum++;
        }
    }
    return sum;
}

int count_words(string text)
{
    int sum = 0;
    int i = 0;
    do
    {
       if (text[i] == ' ')
        {
            sum++;
        }
        i++;
     }
     while (text[i] != '\0');
    return sum + 1;
}

int count_sentences(string text)
{
    int sum = 0;
    int i = 0;
    do
    {
       if (text[i] == '?' || text[i] == '.' || text[i] == '!')
        {
            sum++;
        }
        i++;
     }
     while (text[i] != '\0');
    return sum ;
}