#include <stdio.h>
#include <cs50.h>

bool valid_triangle(float x, float y, float z);

int main(void)
{

}


bool valid_triangle(float x, float y, float z)
// a/ \c
// /_b_\
{
    // check for positive sides
    if ( x <= 0 || y <= 0 || z <= 0)
    {
        return false;
    }

    // check that sum of any two sides greater than third
    if ((x + y <= z) || (x + z <= y) || (y + z <= x))
    {
        return false;
    }

    return true;

}
