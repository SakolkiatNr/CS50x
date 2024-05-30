// Checks the validity of a given credit card number.

#include <cs50.h>
#include <stdio.h>

int calculate_check_sum(long long digits, int length);
int check_card_length(long long digit);
void check_valid(long long ccnumber, int length);

int main(void)
{
    // Prompt user for a credit card
    long long card_digits = get_long_long("Number: ");
    // printf("Output: %lli\n", card_digits);

    int length = check_card_length(card_digits);
    // printf("Length:  %i\n", length);

    int check_sum = calculate_check_sum(card_digits, length);
    // printf("Check sum is %i\n", check_sum);

    // Report whether it is a valid card
    if ((check_sum % 10) != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        check_valid(card_digits, length);
    }
}

// AMEX         16 digits       starts with 34,37XXXX...
// MASTERCARD   16 digits       starts with 51,52,53,54,55XXXX...
// VISA         13,16 digits    starts with 4XXXX...
// INVALID not fall in above categories
// ======================================================================
// Calculate check sum using Luhn's Algorithm

// // Calculate check sum #1 ; StackOverflow
// int calculate_check_sum(long long digits, int lengths)
// {
//     int sum = 0;
//     int ten = 1;
//     // multiplied digits
//     for (int i = 0; i < lengths;i++)
//     {
//         // Power of ten each loop
//         ten *= 10;

//         // multiplied digits
//         if (i%2 != 0)
//         {
//             // if multiplied digits > 10 e.g. 12 -> 1 + 2
//             int product = (((digits % ten) / (ten/10)) * 2);
//             if (product >= 10)
//             {
//                 sum += ((product/10) + (product%10));
//                 printf("Product: %i\n", sum);
//             }
//             else
//             {
//                 sum += product;
//                 printf("Product: %i\n", sum);
//             }
//         }
//         else
//         {
//             sum += (((digits % ten) / (ten/10)));
//             printf("Product: %i\n", sum);
//         }
//     }
//     return sum;

// }

// Calculate check sum #2
// Prevent stack overflow by get the value and reduce digit each time
int calculate_check_sum(long long digits, int length)
{
    int sum = 0;
    // get remainder from last digits
    long long digit = digits;

    for (int i = 0; i < length; i++)
    {
        int product = (digit % 10);
        // multiplied digit
        if (i % 2 != 0)
        {
            product *= 2;
            // if multiplied digit > 10 e.g. 12 -> 1 + 2
            if (product >= 10)
            {
                sum += ((product / 10) + (product % 10));
            }
            else
            {
                sum += product;
            }
        }
        // not multiplied digit
        else
        {
            sum += product;
        }
        digit /= 10;
        // printf("digit = %i\n", product);
    }
    return sum;
}

// Check for card length and starting digits
int check_card_length(long long digit)
{
    int lengths = 1;
    while (digit > 9)
    {
        digit /= 10;
        lengths++;
    }
    return lengths;
}

// Check if card is valid
void check_valid(long long ccnumber, int length)
{
    // AMEX         16 digits       starts with 34,37XXXX...
    // MASTERCARD   16 digits       starts with 51,52,53,54,55XXXX...
    // VISA         13,16 digits    starts with 4XXXX...
    // INVALID not fall in above categories

    // check first 2 digits
    while (ccnumber > 100)
    {
        ccnumber /= 10;
    }
    if ((ccnumber == 34 || ccnumber == 37) && length == 15)
    {
        printf("AMEX\n");
    }
    else if (ccnumber >= 51 && ccnumber <= 55 && length == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (ccnumber >= 40 && ccnumber <= 49 && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
