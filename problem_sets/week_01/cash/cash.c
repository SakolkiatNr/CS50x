#include <cs50.h>
#include <stdio.h>

// quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
int calculate_cash(int cents);

int main(void)
{
    // prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 1);

    int coins = calculate_cash(cents);
    // Print that sum
    printf("%i\n", coins);
}

// calculate total coins
int calculate_cash(int cents)
{
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;

    // greed algorithms
    while (cents > 0)
    {
        // Calculate how many quarters you should give customer
        if (cents >= 25)
        {
            quarters++;
            // Subtract the value of those quarters from cents
            cents = cents - 25;
        }
        // calculate how many dimes you should give customer.
        else if (cents >= 10)
        {
            dimes++;
            // Subtract the value of those quarters from cents
            cents = cents - 10;
        }
        // Calculate how many nickels you should give customer.
        else if (cents >= 5)
        {
            nickels++;
            // Subtract the value of those nickels from remaining cents
            cents = cents - 5;
        }
        else
        {
            // calculate how many pennies you should give customer.
            pennies++;
            // Subtract the value of those pennies from remaining cents
            cents = cents - 1;
        }
    }

    int total_coins = quarters + dimes + nickels + pennies;
    return total_coins;
}
