#include <stdio.h>

int bitAnd(int x, int y){
    return ~(~(x) | ~(y));
}

int bitXor(int x, int y){
    return  ~(~(~x & y) & ~(x & ~y));
}

int thirdBits(void){
    int a = 0x49;
    int b = (a << 9);
    int c = b + a;
    return (c << 18) + c;
}

int fitsBits(int x, int y){
    int a = 33 + ~y;
    int b = ((x << a ) >> a);
    return  !(b + ~x + 1);
}

int sign(int x){
    return (x >> 31) + (((~x)>> 31) & !!(x << 1));
}

int getByte(int x, int y){
    return (x >> ( y << 3) & (0xFF));
} 

int logicalShift(int x, int y){
    int a = (x >> y);
    int b = ~(~0 << (33 + ~y));
    int c = (a & b);
    return ((((!y) << 31) >> 31) & x) +c;
}

int addOK(int x, int y){
    int sum = x + y;
    return !(((x ^ sum) & (y ^ sum)) >> 31);
}

int bang(int x){
    return (((~x + 1) | x) >> 31) + 1;
}

int conditional(int x, int y, int z){
    int a = ((((x >> 31) | ((~x + 1) >> 31)) << 31) >> 31);
     return ((a & y) + (~a & z));
}

int isPower2(int x){
    return !(((x + ~0) >> 30) | (x & (x + ~0)));
}
