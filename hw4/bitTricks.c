#include <stdio.h>

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
  int result = 4;
  result = (result << 3) + result;
  result = (result << 6) + result;
  result = (result << 12) + result;
  result = (result << 24) + result;
  return result;
}

int fitsBits(int x, int n)
{
  int result;
  x >>= n + 0xFFFFFFFF;
  result = (!x | !(x ^ 0xFFFFFFFF));
  return result;
}

int sign(int x)
{
  return (!!x) | (x >> 31);
}

int getByte(int x, int n)
{
  return (x >> 8 * n) & 0xFF;
}

int logicalShift(int x, int n)
{
  return (x >> n) & (0xFFFFFFFF >> n);
}

int addOK(int x, int y)
{
  int sum = x + y;
  int result = !(((sum ^ x) & (sum ^ y)) >> 31);
  return result;
}

int bang(int x)
{
  return ((x | (~x + 1)) >> 31) + 1;
}

int conditional(int x, int y, int z)
{
  x = ((!x) << 31) >> 31;
  return (~x & y) | (x & z);
}

int isPower2(int x)
{
  return !!x & (((x >> 31) + 1) & !(x & (x + ~0)));
}

int main()
{
  printf("bitAnd(6, 5) = %i\n\n", bitAnd(6, 5));

  printf("bitXor(4, 5) = %i\n\n", bitXor(4, 5));

  printf("thirdBits: %i\n\n", thirdBits());

  printf("fitsBits(5,3) = %i\n", fitsBits(5, 3));
  printf("fitsBits(-4,3) = %i\n\n", fitsBits(-4, 3));

  printf("sign(130) = %i\n", sign(130));
  printf("sign(0) = %i\n", sign(0));
  printf("sign(-23) = %i\n\n", sign(-23));

  printf("getByte(0x12345678, 1) = %i\n\n", getByte(0x12345678, 1));

  printf("logicalShift(0x87654321, 4) = %i\n\n", logicalShift(0x87654321, 4));

  printf("addOK(0x80000000, 0x80000000) = %i\n", addOK(0x80000000, 0x80000000));
  printf("addOK(0x80000000, 0x70000000) = %i\n\n", addOK(0x80000000, 0x70000000));

  printf("bang(3) = %i\n", bang(3));
  printf("bang(0) = %i\n\n", bang(0));

  printf("conditional(2, 4, 5) = %i\n\n", conditional(2, 4, 5));

  printf("isPower2(5) = %i\n", isPower2(5));
  printf("isPower2(8) = %i\n", isPower2(8));
  printf("isPower2(0) = %i\n", isPower2(0));
  printf("isPower2(0) = %i\n\n", isPower2(-2147483648));

  return 0;
}