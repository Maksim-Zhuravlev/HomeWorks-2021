#include <stdio.h>
#include <stdlib.h>

void other()
{
    printf("text was printed\n");
    exit(1);
}

void input()
{
    int array[1];
    int x = 1;
    int i = 1;

    while (x)
    {
        printf("%d) please enter a number: ", i);
		scanf("%d", &x);
		array[i] = x;
		if (x == 0) break;
		i++;

    }
}
int main()
{
    printf("Address of other(): %d\n", (int)other);
    input();
    printf("we can not desplay the text\n");
    return 0;
}
