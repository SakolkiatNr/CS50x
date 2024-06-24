#include <stdio.h>

// % Provides the address of something stored in memory
// * Instruc the compiler to go to a location in memory

int main(void)
{
    int n = 50;
    printf("%i\n", n);

    // address of variable
    printf("%p\n", &n);

}
