// Header files
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Storing integer array
    int size = get_int("Enter a size: ");
    int sequence[size];

    // Assign value to an array
    sequence[0] = 1;
    printf("%i\n", sequence[0]);

    // Assign value using for loop
    for (int i =1; i < size; i++)
    {
        // Double the value of array
        sequence[i] = sequence[i - 1] * 2;
        printf("%i\n", sequence[i]);
    }

}
