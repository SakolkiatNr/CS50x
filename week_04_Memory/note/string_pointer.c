
#include <stdio.h>

int main(void)
{
    char *s1 = "HELLO!";

    // printf("%p\n", s1);
    // // 0x61b03e08c004

    // printf("%p\n", &s1[0]);
    // // 0x61b03e08c004

    printf("%c\n", s1[0]);
    printf("%c\n", s1[1]);
    printf("%c\n", s1[2]);

}
