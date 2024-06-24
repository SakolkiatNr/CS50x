#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));

    // Buggy
    // usage: valgrind ./valgrind
    // check for memory lost
    // x[1] = 72;
    // x[2] = 73;
    // x[3] = 33;

    // Fixed
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;
    free(x);

}
