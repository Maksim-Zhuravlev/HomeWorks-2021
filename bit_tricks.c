#include <stdio.h>

int bitAnd(int x, int y)
{
	x = ~x;
	y = ~y;
	int res = x | y;
	res = ~res;
	return res;
}

int bitXor(int x, int y)
{
	int a = x & y, res;
	a = ~a;
	x = ~x;
	y = ~y;
	res = x & y;
	res = ~res;
	res = a & res;
	return res;
}

int thirdBits(void)
{
	int a = 36, res = 36, i = 0;
	for (i; i < 4; i++)
	{
		a = a << 6;
		res = a | res;
	}
	return res;
}

int fitsBits(int x, int n)
{
	n += ~0;
	x = x >> n;
	int a = !x, b, res;
	x += 1;
	b = !x;
	res = a | b;
	return res;
}

int sign(int x)
{
	int a = !x, res;
	x = x >> 31;
	a = a ^ 1;
	res = x | a;
	return res;
}

int getByte(int x, int n)
{
	int a = 255, b = ~8 + 1, res;
	n = 24 + b * n;
	x = x << n;
	x = x >> 24;
	res = a & x;
	return res; 
}

int logicalShift(int x, int n) 
{
	int a = ~0, b, res;
	b = 32 + a * n;
	a = a << b;
	a = ~a;
	x = x >> n;
	res = a & x;
	return res;
}

int addOK(int x, int y) 
{
	int a, res, m = 1, s1, s2, signs2, diff, d, signs1, signm;
	m = m << 31;
	s1 = x | y;
	s2 = x & y;
	signs2 = s2 >> 31;
	m = signs2 ^ m;
	signs1 = s1 >> 31;
	a = signs2 ^ signs1;
	diff = ~a;
	d = 1 & signs1;
	m = m & diff;
	m += s1 + s2 + d;
	signm = m >> 31;
	res = signs2 ^ signm;
	res = res | a;
	res = ~res + 1;
	return res;
}

int bang(int x)
{

	int res, a = ~x + 1;
	x = x >> 31;
	a = a >> 31;
	res = x + a + 1; 
	return res;
}

int conditional(int x, int y, int z)
{
	x = !x;
	x = ~x;
	x = x << 31;
	x = x >> 31;
	int a = ~x, res;
	a = z & a;
	x = x & y;
	res = a + x;
	return res;
}

int isPower2(int x)
{
	int a = x + ~0, res, b = 0;
	a = x & a;
	a = !a;
	a = ~a + 1;
	b = !x;
	res = x >> 31;
	res = ~res;
	b = b + ~1 + 1;
	x = a & b;
	x = ~x + 1;
	res = res & x;
	return res;
}
int main()
{
	return 0;
}