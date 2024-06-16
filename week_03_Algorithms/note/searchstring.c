#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // An array of strings
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    // Search for string
    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        // use string compare to find matching string in C
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    print("Not found\n");
    return 1;
}
