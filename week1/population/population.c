#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int n = start;
    int year = 0;
    while (n < end)
    {
        int born = n / 3;
        int dead = n / 4;
        n = n + born - dead;
        year++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", year);
}
