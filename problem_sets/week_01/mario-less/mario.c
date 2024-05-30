#include <cs50.h>
#include <stdio.h>

void print_row(int brick, int height);

int main(void)
{
    // prompt the user for the pyramid's height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    // print a pyramid of that height
    for (int i = 0; i < height; i++)
    {
        print_row(i, height);
    }
}

void print_row(int brick, int height)
{
    // space
    for (int j = 0; j < (height - brick - 1); j++)
    {
        printf(" ");
    }
    // bricks
    for (int k = 0; k < (brick + 1); k++)
    {
        printf("#");
    }

    printf("\n");
}
