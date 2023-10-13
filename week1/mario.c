#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    /////
    int flag = height;
    int key = 1;

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < flag - 1; i++)
        {
            printf(" ");
        }

        for (int i = 0; i < key; i++)
        {
            printf("#");
        }

        printf("  ");

        for (int i = 0; i < key; i++)
        {
            printf("#");
        }

        flag--;
        key++;

        printf("\n");
    }
}