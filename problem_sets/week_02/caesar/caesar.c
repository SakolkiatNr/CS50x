#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encipher_text(string text, int key);

// argc starts from 1,2,3,...
// argv is an array, start from 0,1,2,...

int main(int argc, string argv[])
{
    // If executed without key in command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Key value must be digit
    int length = strlen(argv[1]);
    for (int i = 0; i < length; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert argv[1] from string to integer
    int key = atoi(argv[1]);
    // printf("Cipher key: %i\n", key);

    // Prompt user for plaintext
    string text = get_string("plaintext: ");

    // Encipher and print cipher text
    encipher_text(text, key);
}

void encipher_text(string text, int key)
{
    // Loop string for each character

    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        // Remain Uppercase
        if (isalpha(text[i]) && isupper(text[i]))
        {
            // Ci = (Pi + k) % 26
            // ASCII for A-Z are 65 - 90
            // set A = 0 ... Z= 25
            // After that add the number back to remain the default ASCII code

            text[i] = (text[i] - 65 + key) % 26 + 65;
        }
        // Remain lowercase
        else if (isalpha(text[i]) && islower(text[i]))
        {
            // ASCII for a-z are 97 - 122
            // set a = 0 ... z = 25
            text[i] = (text[i] - 97 + key) % 26 + 97;
        }
    }

    // Print ciphertext
    printf("ciphertext: %s\n", text);
}
