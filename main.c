#include <stdio.h>

int bitAnd(int x, int y)
{
    return (~(~x | ~y));
}

int bitXor(int x, int y)
{
    return(~(~(x & ~y) & ~(~x & y)));
}

int thirdBits(void)
{
    return (4 | (36 << 3) | (36 << 9) | (36 << 15) | (36 << 21) | (36 << 27));
}

int fitsBits(int x, int n)
{
    int minus = ~1 + 1;
    x = x >> (n + minus);
    return !x | !(x ^ minus);
}

int sign(int x)
{
    int zero = !(x ^ 0);
    return (!zero | (x >> 31));
}

int getByte(int x, int n)
{
    int mask = 0xFF;
    int shift = n << 3;
    mask <<= shift;
    int res = x & mask;
    return ((res >> shift) & 0xFF);
}

int logicalShift(int x, int n)
{
    return ((unsigned int)x >> n);
}

int addOK(int x, int y)
{
    int sign_unsigned_sum = (unsigned int)(x + y) >> 31, sign_unsigned_x = (unsigned int)x >> 31, sign_unsigned_y = (unsigned int)y >> 31;
    return ( (sign_unsigned_x ^ sign_unsigned_y) | ( !(sign_unsigned_sum ^ sign_unsigned_x) ) );
}

int bang(int x)
{
    int minus = (~1 + 1);
    int zero = ~((x >> 31) & 1) & ((x ^ (x + minus)) >> 31) & 1;
    return (zero);
}

int conditional(int x, int y, int z)
{
    return (((~(!(!x)) + 1) & y) | ((~(!x) + 1) & z));
}

int isPower2(int x)
{
    int more_zero = (x >> 31) & 1, zero = !(x ^ 0), minus = (~1 + 1);
    return (!more_zero & !zero & !(x & (x + minus)));
}

int main()
{
    return 0;
}