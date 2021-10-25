
#include <stdio.h>


int conditional(int x, int y, int z)
 {
	int value;
	x = !(!x);
    value = ((1 + ~x) & y) + (~(1 + ~x) & z);                  
	return value;
}






int isPower2(int x)
{ 
	int f1, f2, result;
	f1 = x != 0;
	f2 = ((x & (x - 1)) == 0);
	result = f1 & f2;

	return result;
}






int bang(int x)
{
	int res;
	
	x = x | (~x + 1);
	res = (x >> 31) + 1;

	return res;

}






int addOK(int x, int y)
{
	int f1, f2,f3, sum;
	
	sum = x + y;
	f1 = x ^ sum;
	f2 = y ^ sum;
	f3 = f1 & f2;
	
	return !(f3>>31);
}






int logicalShift(int x, int n)
{
	int res;
	x = x >> 1;
	x = x & 2147483647;
	
		return (x >> (n - 1));
}






int getByte(int x, int n)    //Ответ выдается в десятичной системе счисления
{
	x = x >> 8 * n;

	return (x & 0xFF);
}







int sign(int x)
{

	return (x >> 31) | (!(!x));
}






int fitsBits(int x, int n)
{
	int A, B;
	x = x >> (n - 1);
	A = !(x + 1);
	x = !x;
	B = x | A;
	 
	return B;
}





int thirBit(void)
{
	int mult=36, sum= 36;

	for (int i = 1 ; i <= 4; i = i + 1)
	{
		mult = sum + (mult << 6);
		printf("mult: %d\n", mult);
		
	}
	return mult;
}





int bitXor(int x, int y)
{
     int mult1, mult2, sum;

	 mult1 = ~x & y; 
	 mult2 = x & ~y;
	 sum = ~(~mult1 & ~mult2);
		 return sum;

}





int bitAnd(int x, int y)
{
		int A;
		
		A = ~(~x | ~y);

		return A;

}


int main(void)
{ 
	return 0;
}