#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// type './mario <number>' in command-line to hold the value of int before execute
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./mario number\n");
        return 1;
    }
    // turn string to integer value from command prompt using atoi
    int height = atoi(argv[1]);
}
