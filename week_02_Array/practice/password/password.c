// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int length = strlen(password);

    // set conditions
    bool upper, lower, number, symbol = false;

    // Iterate to each character
    for (int i = 0; i < length; i++)
    {
        // at least one uppercase
        if (isupper(password[i]))
            upper = true;

        // at least one lowercase
        else if (islower(password[i]))
            lower = true;

        // at least one number
        else if (isdigit(password[i]))
            number = true;

        // at least one symbol
        else if (ispunct(password[i]))
            symbol = true;
    }

    // Check condition
    if (upper == true && lower == true && symbol == true && number == true)
    {
        return true;
    }

    return false;
}
