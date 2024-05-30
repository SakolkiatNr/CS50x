#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}

// use command line clang as follow
// clang -o hello hello.c -lcs50
