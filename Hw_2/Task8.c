#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_Simple(int a)
{
    int simple = 1, up_To = ((int)sqrt(a)) + 1;
    for (int d = 2; d < up_To; d++) {
        if (a % d == 0) {
            simple = 0;
            break;
        }
    }
    return simple;
}

int main()
{
    int x;
    printf("Input your number: ");
    scanf("%d", &x);
    for (int i = 1; i <= x; i++) {
        if (is_Simple(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}
