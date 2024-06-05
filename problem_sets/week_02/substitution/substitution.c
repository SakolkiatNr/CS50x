#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validate_key(string key);
void encipher(string text, string key);

int main(int argc, string argv[])
{
    // If executed without key in command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    // Get the key
    string key = argv[1];

    // Validate key
    if (validate_key(key) != 1)
    {
        return 1;
    }
    // Get plaintext
    string text = get_string("plaintext: ");

    // Encipher and print
    encipher(text, key);
    // Print ciphertext

    return 0;
}

int validate_key(string key)
{
    // Validate key

    // Check key length
    int length = strlen(key);

    if (length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 0;
    }
    else
    {
        // Iterate to each char
        for (int i = 0; i < length; i++)
        {
            // Turn lowercase to uppercase
            if (islower(key[i]))
            {
                key[i] = (char) toupper((unsigned char) key[i]);
            }
            // Check non-alphabetic characters
            if (isalpha(key[i]) == 0)
            {
                printf("Key must only contain alphabetic characters.\n");
                return 0;
            }
            // Check repeated characters (case-insensitive)
            for (int j = 0; j < length; j++)
            {
                if ((key[i] == key[j]) && (i != j))
                {
                    printf("Key must not contains repeated characters.\n");
                    return 0;
                }
            }
        }
        // Valid key
        return 1;
    }
    return 0;
}

void encipher(string text, string key)
{
    string ciphertext = text;
    int length = strlen(text);

    // Get position from plaintext
    for (int i = 0; i < length; i++)
    {
        // Uppercase
        if (isalpha(text[i]) && isupper(text[i]))
        {
            // Get key position from plaintext
            int position = text[i] - 65;
            // Map position to KEY
            ciphertext[i] = key[position];
        }
        else if (isalpha(text[i]) && islower(text[i]))
        {
            int position = text[i] - 97;
            ciphertext[i] = (char) tolower((unsigned char) key[position]);
        }
    }

    // print ciphertext
    printf("ciphertext: %s\n", ciphertext);
}
