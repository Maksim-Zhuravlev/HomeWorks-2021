#include<stdio.h>
#include<string.h>

#define MAXLINE 100 // максимальная длина строки

int main() 
{
    char a[MAXLINE] = "Hello, world, my bike is my life or my problem";
    char b[MAXLINE] = "my";
    int result;

    printf("%i", substr(a, b));
}

int substr(char* a, char* b) // указатели передаются в функцию
{
    int count = 0;
    char* tmp = a;
    while (tmp = strstr(tmp, b)) /* начинаем сдвигать указатель tmp и он начинает указывать не на начало строки a, а на место, 
 где начинается первое вхождение строки b. если разыменовать a и напечатать значение строки, то будет
Hello, world, my bike is my life or my problem, а если разыменовать tmp после присваивания ей результата strstr, то получим
my bike is my life or my problem. если мы попытаемся выполнить strstr с поиском my в этой строке, то мы снова получим
my bike is my life or my problem */
    {
        printf("Position: %d\n", (int)(tmp - a));
        ++count;
        ++tmp; /* именно поэтому мы сначала инкрементируем указатель и он сдвигается на один символ и становится равен
        y bike is my life or my problem. а когда мы на этой строке выполняем strstr, то получаем
my life or my problem */
    }
    return count;
}