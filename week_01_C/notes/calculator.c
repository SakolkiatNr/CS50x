#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt user for x
    int x = get_int("x: ");

    //Prompt user for y
    int y = get_int("y: ");

    //Perform addition
    printf("%i\n", add(x, y));
}

int add(int a, int b)
{
    return a + b;
}

---
int main(void)
{
    //Prompt user for x
    long x = get_long("x: ");

    //Prompt user for y
    long y = get_long("y: ");

    //Perform addition
    printf("%li\n", x+ y)
}
