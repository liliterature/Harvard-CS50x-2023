#include <cs50.h>
#include <stdio.h>
int getsize(long n);

int main(void)
{
    long n = get_long("Number: ");
    int sum = 0;
    long key = n;
    // second_last
    for (int i = 0; i < 9; i++)
    {
        int w = ((key / 10) % 10) * 2;
        if (w >= 10)
        {
            int a = w / 10;
            int b = w % 10;
            w = a + b;
        }
        // printf("w = %i\n" , w);
        sum += w;
        // printf("sum = %i\n" , sum);
        key /= 100;
    }
    // printf(" %i\n", sum);
    // first_last
    long flag = n;
    for (int j = 0; j < 8; j++)
    {
        int x = flag % 10;
        sum += x;
        flag /= 100;
    }
    /// printf("sum = %i\n", sum);
    // legit
    int km = 0;
    if (sum % 10 == 0)
    {
        km = 1;
    }
    /// judge card
    int num = getsize(n);
    if (km == 1)
    {
        if (num == 13)
        {
            printf("VISA\n");
        }
        else if ((num == 15 && n / 10000000000000 == 34) || (num == 15 && n / 10000000000000 == 37))
        {
            printf("AMEX\n");
        }
        else if (num == 16)
        {
            if (n / 1000000000000000 == 4)
            {
                printf("VISA\n");
            }
            else if (n / 100000000000000 == 51 || n / 100000000000000 == 52 || n / 100000000000000 == 53 ||
                     n / 100000000000000 == 54 || n / 100000000000000 == 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
////
int getsize(long n)
{
    int key = 0;
    while (n > 0)
    {
        n /= 10;
        key++;
    }
    return key;
}