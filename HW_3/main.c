#include <stdio.h>

int bitAnd(int x, int y)
{
    int result = ~(~x | ~y);
    return result;
}

int bitXor(int x, int y)
{
    int result = ~(x & y) & ~(~x & ~y);
    return result;
}

int thirdBits(void)
{
    int result = (146 << 22) | (73 << 14) | (73 << 5) | 4;
    return result;
}

int fitsBits(int x, int n)
{
    int result;
    x >>= n + (~1 + 1);
    result = (!x | !(x ^ (~1 + 1)));
    return result;
}

int sign(int x)
{
    int result = (!!x) | (x >> 31);
    return result;
}

int getByte(int x, int n)
{
    int result = (x >> 8 * n) & 0xFF;
    return result;
}

int logicalShift(int x, int n)
{
    int result = (x >> n) & (0xFFFFFFFF >> n);
    return result;
}

int addOK(int x, int y)
{
    int sum = x + y;
    int result = !(((sum ^ x) & (sum ^ y)) >> 31);
    return result;
}

int bang(int x)
{
    int result = ((x | (~x + 1)) >> 31) + 1;
    return result;
}

int conditional(int x, int y, int z)
{
    int result = (((1 + ~(!(!x))) & y) | ((1 + ~(!x)) & z));
    return result;
}

int isPower2(int x)
{
    int result = !(((x + ~0) >> 30) | (x & (x + ~0)));
    return result;
}

int main()
{
    printf("bitAnd(6, 5) = %d \n\n", bitAnd(6, 5));

    printf("bitXor(4, 5) = %d \n\n", bitXor(4, 5));

    printf("thirdBits: %d \n\n", thirdBits());

    printf("fitsBits(5,3) = %d \n", fitsBits(5, 3));
    printf("fitsBits(-4,3) = %d \n\n", fitsBits(-4, 3));

    printf("sign(130) = %d \n", sign(130));
    printf("sign(0) = %d \n", sign(0));
    printf("sign(-23) = %d \n\n", sign(-23));

    printf("getByte(0x12345678, 1) = %d \n\n", getByte(0x12345678, 1));

    printf("logicalShift(0x87654321, 4) = %d \n\n", logicalShift(0x87654321, 4));

    printf("addOK(0x80000000, 0x80000000) = %d \n", addOK(0x80000000, 0x80000000));
    printf("addOK(0x80000000, 0x70000000) = %d \n\n", addOK(0x80000000, 0x70000000));

    printf("bang(3) = %d \n", bang(3));
    printf("bang(0) = %d \n\n", bang(0));

    printf("conditional(2, 4, 5) = %d \n\n", conditional(2, 4, 5));

    printf("isPower2(5) = %d \n", isPower2(5));
    printf("isPower2(8) = %d \n", isPower2(8));
    printf("isPower2(0) = %d \n\n", isPower2(0));

    return 0;
}