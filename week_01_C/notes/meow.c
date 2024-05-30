#include <stdio.h>

int main(void)
{
    int i = 3;
    while (i > 0)
    {
        printf("Meow\n");
        i--;
    }
}

---

int main(void)
{
    int i = 1;
    while (i <= 3)
    {
        printf("meow\n");
        i++;
    }
}

---
// start from 0
int main(void)
{
    int i = 0;
    while (i < 3)
    {
        printf("meow\n");
        i++;
    }
}

--

//using for loop

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("meow\n")
    }
}

--
