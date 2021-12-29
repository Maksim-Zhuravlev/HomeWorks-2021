#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_LENGTH 100

int signOfArray(int array[], int length)
{
    int i, count = 0;
    for (i = 0; i < length; i++)
    {
        if (array[i] == 0)
        {
            return printf("Sign of the array = 0\n");
            break;
        }
        else if (array[i] < 0)
        {
            count += 1;
        }
    }
    if (count % 2 == 0)
    {
        return printf("Sign of the array = 1\n");
    }
    else
    {
        return printf("Sign of the array = -1\n");
    }
}

int main() {
    int array[MAX_LENGTH];
    int i, length;
    printf("Enter the length of array: ");
    scanf("%d", &length);
    printf("Enter the elements of array:\n");
    for (i = 0; i < length; i++)
        scanf("%d", &array[i]);
    signOfArray(array, length);

    return 0;
}