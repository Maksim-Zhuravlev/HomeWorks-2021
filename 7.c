// Arian Bagheri Nezhad
// 21. Б16. мм
// HomeWork_7

#include <stdio.h>
#include <stdlib.h>

void other();
void input();

int main (void)
{
    printf("The adress of other: %d\n\n", (int)other);

    input();

    printf("You can NOT see the printing of this text on the screen\n\n");

    return 0;
}

void other()
{
    printf("You can see the printing of this text on the screen\n\n");
    exit(1);
}

void input()
{
    int array[1];
    int x = 1;
    int i = 1;

    while (x)
    {
        printf("%d. Enter number(to exit, enter 0): ", i);
        scanf("%d", &x);

        if (x == 0) break;

        array[++i] = x;
    }
}