#include <stdio.h>
#include <stdlib.h>

int main()

{
    int n;
    scanf("%d", &n);

    int arr[100000];

    for (int i = 0; i <= n; i++)
        arr[i] = 1;

    for (int i = 2; i <= n; i++)
        if (arr[i] == 1)
            for (int j = 2; j * i <= n; j++)
            {
                arr[ j*i ] = 0;
            }

    for (int i = 2; i <= n; i++)
        if (arr[i] == 1)
        {
            printf("%d ", i);
        }


return 0;

}
