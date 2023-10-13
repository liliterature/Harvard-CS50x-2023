#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    //转换字母全为大写or小写，为了用ascii码建立起字母和数组的联系
    //以小写a为例，则减去97作为数组第一位,依此类推
    //似乎也可以通过isupper这种函数来删除符号？
    int length = strlen(word);
    // compute
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        if (isupper(word[i]))
        {
            sum += POINTS[word[i] - 65];
        }
        else if (islower(word[i]))
        {
            sum += POINTS[word[i] - 97];
        }
    }
    return sum;
}
