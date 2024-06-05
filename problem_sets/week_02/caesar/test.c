#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    // int 65 - 90 are A-Z
    // int 97 - 122 are a-z
    char a  = get_char("char: ");
    bool c = isdigit(a);
    if (isdigit(a))
    {
        printf("it's digit: %i\n", c);
    }
}
