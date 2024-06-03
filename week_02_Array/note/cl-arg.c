#include <cs50.h>
#include <stdio.h>

// argc starts from 1,2,3,...
// argv is an array, start from 0,1,2,...
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
        //                         ^ print the argument position 1
    }
    else
    {
        printf("hello, world\n");
    }
}
