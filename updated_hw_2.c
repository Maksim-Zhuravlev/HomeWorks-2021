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
    int res = 36;
    res = (res << 6) | res;
    res = (res << 6) | res;
    res = (res << 6) | res;
    res = (res << 6) | res;
    return (res);
}

int fitsBits(int x, int n)
{
    int minus = ~1 + 1;
    x = x >> (n + minus);
    return !x | !(x ^ minus);
}

int sign(int x)
{
    int shift = 31;
    int null = !(x ^ 0);
    return !null | (x >> shift);
}

int getByte(int x, int n)
{
    int mask = 0xFF;
    int shift = n << 3;
    mask <<= shift;
    int res = x & mask;
    return (res >> shift) & 0xFF;
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
    return (~((x >> 31) & 1) & ((x ^ (x + (~1 + 1))) >> 31) & 1);
}

int conditional(int x, int y, int z)
{
    return (((~(!(!x)) + 1) & y) | ((~(!x) + 1) & z));
}

int isPower2(int x)
{
    int moreNull = (x >> 31) & 1;
    int null = !(x ^ 0);
    return !moreNull & !null & !(x & (x + (~1 + 1)));
}

int main()
{
    return 0;
}


