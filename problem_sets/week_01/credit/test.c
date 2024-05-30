#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // check remainder
    int test = (436014/100);
    printf("%i\n", test);

    // power of ten
    int ten = 1;
    int power = get_int("Power :");
    for (int i=0; i < power;i++)
    {
        ten *= 10;
    }
    printf("%i\n", ten);
}
