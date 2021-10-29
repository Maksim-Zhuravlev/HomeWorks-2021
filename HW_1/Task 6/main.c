#include <stdio.h>

#define MAX_LEN 256

int main()
{
    int array[MAX_LEN];
    int len_arr;
    int count = 0;
    int flag = 0;

    printf("This program prints the product sign of the array elements.\n");
    printf("Enter the length of array: ");
    scanf("%d", &len_arr);

    while (len_arr <= 0)
    {
        printf("You cannot input negative numbers or letters. Please try again.\n");

        char clean = 0;

        while (clean != '\n' && clean != EOF)
        {
            clean = getchar();
        }
        printf("Enter the length of array: ");
        scanf("%d", &len_arr);
    }

    printf("Enter the natural elements of array:\n");

    for (int i = 0; i < len_arr; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < len_arr; i++)
    {
        if (array[i] == 0)
        {
            flag = 1;
            printf("Array product sign = 0\n");
            break;
        }
        if (array[i] < 0)
            count += 1;
    }
    if (flag == 0)
    {
        if (count % 2 == 0)
        {
            printf("Array sign -- '+'.\n");
        }
        else
        {
            printf("Array sign -- '-'.\n");
        }
    }
    return 0;
}