#include <stdio.h>
#include <stdlib.h>

int main()

{
    char s1[10000], s[10000];

    scanf("%s", s);
    scanf("%s", s1);

    int l = strlen(s);
    int l1 =strlen(s1);

    int j = 0, c = 0;

    for(int i = 0; i<l-l1+1; i++)
    {
        j = 0;

        while ( (j < l1)&&( s[i+j] == s1[j] ) )
        {
            j++;
        }

        if (j == l1)
        {
            c++
        };
}

    printf("%d", c);

    return 0;
}
