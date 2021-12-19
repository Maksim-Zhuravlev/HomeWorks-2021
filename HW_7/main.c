#include <stdio.h>
#include <stdlib.h>

void other()
{
    printf("Hello from other()! You are hacked ;)\n");
    exit(1);
}

void input()
{
    int arr[1];
    int x = 0;
    printf("Enter 1 number: ");
    scanf("%d", &x);
    arr[0] = x;
    printf("Enter 2 number: ");
    scanf("%d", &x);
    arr[1] = x;
    printf("Enter 3 number: ");
    scanf("%d", &x);
    arr[2] = x;
    printf("Enter 4 number (other() address or 0 to skip): ");
    scanf("%d", &x);
    if (x != 0)
    {
        arr[3] = x;
    }
}

int main()
{
    printf("Address of other(): %d\n", (int)other);
    input();
    printf("No stack overflow here.\n");
    return 0;
}