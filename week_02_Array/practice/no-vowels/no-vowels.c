// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Declare function prototype
void replace(string text);

int main(int argc, string argv[])
{
    // Accept single command-line
    if (argc != 2)
    {
        printf("Usage: ./novowels word\n");
        return 1;
    }

    string text = argv[1];
    replace(text);


}

void replace(string text)
{
    int str_length = strlen(text);
    string replaced_text = text;

    // Iterate to each char
    for (int i = 0; i < str_length; i++)
    {
        switch (replaced_text[i])
        {
            case 'a':
                replaced_text[i] = '6';
                break;
            case 'e':
                replaced_text[i] = '3';
                break;
            case 'i':
                replaced_text[i] = '1';
                break;
            case 'o':
                replaced_text[i] = '0';
                break;

            default:
                break;
        }
    }
    printf("%s\n", replaced_text);
}
