#include <stdio.h>
// conditional – аналог тернарного оператора x ? y : z
int conditional(int x, int y, int z)
{
	int value;

	x = !(!x);
	value = ((1 + ~x) & y) + (~(1 + ~x) & z);

	return value;
}
///////////////////////////////////////////////
// isPower2 - возвращает 1, если x – степень 2, иначе 0
int isPower2(int x)
{
	int  f1, f2, f3, result;

	f1 = (x != 0);
	f2 = ((x & (x - 1)) == 0);
	f3 = (x != -2147483648);
	result = f1 && f2 && f3;

	return result;
}
///////////////////////////////////////////////
// Bang - вычисляет !x без использования !
int bang(int x)
{
	int res;

	x = x | (~x + 1);
	res = (x >> 31) + 1;

	return res;
}
///////////////////////////////////////////////
// addOK - проверяет, может ли x + y быть вычислено без переполнения
int addOK(int x, int y)
{
	int f1, f2, f3, sum;

	sum = x + y;
	f1 = x ^ sum;
	f2 = y ^ sum;
	f3 = f1 & f2;

	return !(f3 >> 31);
}
///////////////////////////////////////////////
// logicalShift - сдвигает биты x вправо поправилам логического сдвига
int logicalShift(int x, int n)
{
	int res;

	x = x >> n;
	res = x & 4294967295;

	return res;
}
///////////////////////////////////////////////
// getByte - извлекает n-ый байт из x
int getByte(int x, int n)    //Ответ выдается в десятичной системе счисления
{
	x = x >> 8 * n;

	return (x & 0xFF);
}
///////////////////////////////////////////////
// Sign -возвращает 1, 0 и -1, если x > 0, x == 0, x < 0 соответственно
int sign(int x)
{
	return (x >> 31) | (!(!x));
}
///////////////////////////////////////////////
// fitsBits - возвращает 1, если x может быть представлен на машине с n-разрядами (доп.код)
int fitsBits(int x, int n)
{
	int A, B;

	x = x >> (n - 1);
	A = !(x + 1);
	x = !x;
	B = x | A;

	return B;
}
///////////////////////////////////////////////
// thirBits - возвращает int, каждый третий бит которого, считая с младшего, 1, остальные биты 0
int thirBits(void)
{
	int f;

	f = 4 + 32 + 256 + 2048 + 16384;
	f = f + (f << 15);

	return f;
}
///////////////////////////////////////////////
// bitXor - x^y, используя ~ and &
int bitXor(int x, int y)
{
	int mult1, mult2, sum;

	mult1 = ~x & y;
	mult2 = x & ~y;
	sum = ~(~mult1 & ~mult2);

	return sum;
}
///////////////////////////////////////////////
// bitAnd - x&y, используя ~ and |
int bitAnd(int x, int y)
{
	int A;

	A = ~(~x | ~y);

	return A;
}
///////////////////////////////////////////////
int main(void)
{
	return 0;
}