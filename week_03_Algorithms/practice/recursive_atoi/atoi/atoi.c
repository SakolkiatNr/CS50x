#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // ASCI code for number are in range of 48 - 57
    int num = 0;
    // TODO

    // Base case
    if (strlen(input) == 1)
    {
        // e.g. if string is '0' then the int value of '0' is 48
        // subtract to convert into integer and store value to num
        num = (int) input[0] - '0';
        return num;
    }

    // Recursive case
    else
    {
        // Store digit string to temp value
        string current_digit = input;
        int n = strlen(current_digit);

        // remove last element of digit string
        char last_digit = current_digit[n - 1];
        current_digit[n - 1] = '\0';

        num = 10 * convert(current_digit) + (last_digit - '0');
        return num;
    }
}
