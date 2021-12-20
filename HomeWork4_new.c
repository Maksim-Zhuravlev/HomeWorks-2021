//Arian Bagheri Nezhad
// 21. Б16 мм
// HomeWork_4

#include <stdio.h>

#define MAX 31

int bitAnd(int x, int y);
int bitXor(int x, int y);
int thirdBits();
int fitsBits(int x, int n);
int sign(int x);
int getByte(int x, int n);
int logicalShift(int x, int n);
int addOK(int x, int y);
int bang(int x);
int conditional(int x, int y, int z);
int isPower2(int x);

int main ()
{
    printf("\nHomeWork 4\n\n");
    printf("%d\n\n", conditional(0,4,5));

    return 0;
}

int bitAnd(int x, int y)
{
	return ~(~(x) | ~(y));
}

int bitXor(int x, int y)
{
	return ~(~(~x & y) & ~(x & ~y));
}

int thirdBits()
{
	int result = 4;

	result = (result << 3) + result;
	result = (result << 6) + result;
	result = (result << 12) + result;
	result = (result << 24) + result;
    
	return result;
}

int fitsBits(int x, int n)
{
	x = x >> (n + ~0);
	
	return !x | !(x + 1);
}

int sign(int x)
{
	return (!!x) | (x >> MAX);
}

int getByte(int x, int n)
{
	x = x >> (n << 3);

	return x & 255;
}

int logicalShift(int x, int n)
{
    int arithmetic_right_shift_x = (x >> n);

	return arithmetic_right_shift_x & ~((x >> MAX) << (MAX + ~n + 1) << 1);
}

int addOK(int x, int y)
{
    int sum_x = (x+y) ^ x, sum_y = (x + y) ^ y;
	
    return !((sum_x & sum_y) >> 31);
}

int bang(int x)
{
	return (((~x + 1) | x) >> MAX) + 1;
}

int conditional(int x, int y, int z)
{
	return (y & (((!!x) << MAX) >> MAX)) | (z & (((!x) << MAX) >> MAX));
}

int isPower2(int x)
{
	return !(((x + ~0) >> (MAX - 1)) | (x & (x + ~0)));
}