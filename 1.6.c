#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int arr[n];

    scanf("%d", &n);

    for (int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int t = 0;

    for (int i = 0; i<n; i++)
    {
        if (arr[i] == 0)
        {
            printf("0");
            return 0;
        }

        if (arr[i] < 0)
        {
            t = (t+1)%2;
        }
    }

    if (t == 0)
    {
        printf("+");
    }
    else
    {
        printf("-");
    }

return 0;
}
