//Arian Bagheri Nezhad
// 21. Б16 мм
// HomeWork_4

#include <stdio.h>

#define MAX 31

int bit_and(int x, int y);
int bit_xor(int x, int y);
int third_bits();
int fits_bits(int a, int d);
int sign(int x);
int get_byte(int a, int d);
int logical_shift(int a, int d);
int add_oK(int x, int y);
int bang(int x);
int conditional(int x, int y, int z);
int is_power2(int x);

int main ()
{
    printf("\nHomeWork 4\n\n");
    printf("%d\n\n", conditional(0,4,5));

    return 0;
}

// x & y using ~ and |
int bit_and(int x, int y)
{
	return ~(~(x) | ~(y));
}

// x ^ y using ~ and &
int bit_xor(int x, int y)
{
	return ~(~(~x & y) & ~(x & ~y));
}

/* returns an int, every third bit of which,
counting from the least significant, is 1
the rest of the bits are 0*/
int third_bits()
{
	int result = 4;

	result = (result << 3) + result;
	result = (result << 6) + result;
	result = (result << 12) + result;
	result = (result << 24) + result;
    
	return result;
}

// returns 1 if x can be represented on an n-bit machine (add-on code)
int fits_bits(int a, int d)
{
	a = a >> (d + ~0);
	
	return !a | !(a + 1);
}

// returns 1, 0 and -1 if x> 0, x == 0, x <0 respectively
int sign(int x)
{
	return (!!x) | (x >> MAX);
}

// retrieves the nth byte from x
int get_byte(int a, int d)
{
	a = a >> (d << 3);

	return a & 255;
}

// shifts the bits of x to the right according to the logical shift rules
int logical_shift(int a, int d)
{
    int arithmetic_right_shift_a = (a >> d);

	return arithmetic_right_shift_a & ~((a >> MAX) << (MAX + ~d + 1) << 1);
}

// checks if x + y can be evaluated without overflow
int add_oK(int x, int y)
{
    int sum_x = (x+y) ^ x, sum_y = (x + y) ^ y;
	
    return !((sum_x & sum_y) >> 31);
}

// Computes! X without using
int bang(int x)
{
	return (((~x + 1) | x) >> MAX) + 1;
}

// analogue of the ternary operator x? y: z
int conditional(int x, int y, int z)
{
	return (y & (((!!x) << MAX) >> MAX)) | (z & (((!x) << MAX) >> MAX));
}

// возвращает 1,если x – степень 2, иначе 0
int is_power2(int x)
{
	return !(((x + ~0) >> (MAX - 1)) | (x & (x + ~0)));
}