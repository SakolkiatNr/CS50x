#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;

    // Get an address
    printf("%p\n", p);

    // Get a value
    printf("%i\n", *p);
}
