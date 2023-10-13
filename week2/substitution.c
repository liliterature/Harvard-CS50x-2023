#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // error
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    int dup[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        // make sure all elements are letters
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain letters.\n");
            return 1;
        }
        // make sure no duplicate
        int k = tolower(argv[1][i]) - 'a'; // unique key
        if (dup[k])                        // if there is another same key
        {
            printf("Key must no repeat");
            return 1;
        }
        dup[k] = 1;
    }

    // translate plaintext
    string plaintext = get_string("plaintext:  ");
    string ciphertext = plaintext;

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (islower(plaintext[i]))
        {
            ciphertext[i] = tolower(argv[1][plaintext[i] - 'a']);
        }
        else if (isupper(plaintext[i]))
        {
            ciphertext[i] = toupper(argv[1][plaintext[i] - 'A']);
        }
    }
    printf("ciphertext: %s\n", ciphertext);
}