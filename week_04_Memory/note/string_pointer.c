#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    char *s1 = "HELLO!";

    printf("%p\n", s);
    // 0x61b03e08c004

    printf("%p\n", &s[0]);
    // 0x61b03e08c004

    printf("%p\n", &s[1]);
    // 0x61b03e08c005

    printf("%p\n", &s[2]);
    // 0x61b03e08c006

    printf("%p\n", &s[3]);
    // 0x61b03e08c007
}
