#include <stdio.h>
#include <stdlib.h>

void other(){
    printf("buffer overflow");
}

void input(){
    int num;
    int i = 0;
    int arr[1];

    printf("Enter the address of other() on the 7 number. "
           "Enter 0 to stop.\n");

    while(1)
    {
        printf("Type the %d number:", i + 1);
        scanf("%d", &num);

        if (num == 0)
        {
            return;
        }

        arr[i++] = num;
    }
}


int main()
{
    printf("The address of other() is %d\n", other);
    input();

    return 0;
}
