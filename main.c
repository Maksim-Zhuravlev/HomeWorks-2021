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
    return (4 | (292 << 3) | (292 << 12) | (292 << 21));
}

int fitsBits(int x, int n)
{
    int minus = ~1 + 1;
    x = x >> (n + minus);
    return !x | !(x ^ minus);
}

int sign(int x)
{
    int minus = ~1 + 1;
    return ((!(x >> 31)) + ( !( !(x >> 31) ) ) );
}

int getByte(int x, int n)
{
    return (x << ((4 + ~n) << 3)) >> 24;
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

int bang(int x) {
    return ((x | (~x + 1)) >> 31) & 1;
}

int conditional(int x, int y, int z)
{
    return (((~(!(!x)) + 1) & y) | ((~(!x) + 1) & z));
}

int isPower2(int x)
{
    return (!(x & (x + ~0))) & !(x >> 31);
}

int main()
{
    return 0;
}


