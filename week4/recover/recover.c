#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define BLOCK_SIZE 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // If your program is not executed with exactly one command-line argument
    // it should remind the user of correct usage, and main should return 1.
    if (argc != 2)
    {
        printf("Wrong command-line argument");
        return 1;
    }
    // open card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Open failure");
        return 1;
    }
    // get signatures, (buffer[3] & 0xf0) == 0xe0
    BYTE buffer[BLOCK_SIZE];
    int file_count = 0;
    FILE *jfile = NULL;
    while (fread(buffer, 1, BLOCK_SIZE, card) == BLOCK_SIZE)
    {
        // start
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // deal with previous jfile
            if (jfile != NULL)
            {
                fclose(jfile);
            }
            // wait for write
            char filename[8];
            sprintf(filename, "%03i.jpg", file_count++);
            jfile = fopen(filename, "w");
            if (jfile == NULL)
            {
                printf("Open failure");
                return 1;
            }
        }
        // only through start, jfile could be !=NULL
        if (jfile != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, jfile);
        }
    }
    fclose(jfile);
    fclose(card);
}
