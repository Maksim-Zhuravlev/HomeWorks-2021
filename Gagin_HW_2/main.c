int bitAnd(int x, int y)
{
	return ~(~x | ~y);
}

int bitXor(int x, int y)
{
	return ~(x & y) & ~(~x & ~y);
}

int thirdBits()
{
	return (292 << 21) | (292 << 12) | (292 << 3) | 292;
}

int fitsBits(int x, int n)
{
	return !(x ^ ((x << (33 + ~n)) >> (33 + ~n)));
}

int sign(int x)
{
	return x >> 31 | !(!x);
}

int getByte(int x, int n)
{
	return (x >> (n << 3)) & 255;
}

int logicalShift(int x, int n)
{
	int mask = ((1 << 31) >> n) << 1;
	return (x >> n) & ~mask;
}

int addOK(int x, int y)
{
	int sign_check = 1 << 31;
	int sign_x = sign_check & x;
	int sign_y = sign_check & y;
	int sign_sum = sign_check & (x + y);
	int problem_1 = !(sign_x ^ sign_y);   // same sign
	int problem_2 = !(sign_x ^ sign_sum); // == 0 if x + y and x have a different sign - thats when an overfolow may occur
	return (!problem_1) | problem_2;
}

int bang(int x)
{
	return ((x >> 31 | !(!x)) + 1) & 1;
}

int conditional(int x, int y, int z)
{
	int mask = ~(!(!x) - 1);
	return (mask & y) | (~mask & z);
}

int isPower2(int x)
{
	return !(x & (x + ~(x >> 31))) & !(!x);
}

int main()
{
	return 0;
}
