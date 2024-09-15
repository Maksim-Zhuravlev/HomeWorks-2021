#include <stdio.h>

int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

int bitXor(int x, int y) {
    return ~(x & y) & ~(~x & ~y);
}

int thirdBits() {
    int res = 36, step = 6, first = 36;
    int step1 = step + step;
    int step2 = step1 + step1;
    res |= (res << step);
    res |= (res << step1);
    res |= (first << step2);
    return res;
}


int fitsBits(int x, int n) {
    int shift = 32 + (~n + 1);
    int newNum = x << shift;
    newNum >>= shift;
    return !(x ^ newNum);
}

int sign(int x) {
    int shift = 31;
    int is0 = !(x ^ 0);
    return !is0 | (x >> shift);
}


int getByte(int x, int n) {
    int mask = 0xFF;
    int shift = n << 3;
    mask <<= shift;
    int res = x & mask;
    return (res >> shift) & 0xFF;
}

int logicalShift(int x, int n) {
    int beg = x;
    int res;
    int isD0 = !(n ^ 0);
    int mask = (1 << (32 + (~n + 1)));
    mask += (~1 + 1);
    x >>= n;
    res = x & mask;
    return ((~isD0 + 1) & beg) | (~(~isD0 + 1) & res);
}

int addOK(int x, int y) {
    int sgnA = (x >> 31) & 1,
            sgnB = (y >> 31) & 1;
    int sum = x + y;
    int sgnAB = (sum >> 31) & 1;
    return (!sgnA | !sgnB | sgnAB) & (sgnA | sgnB | !sgnAB);

}

int bang(int x) {
    int is0 = ~((x >> 31) & 1) & ((x ^ (x + (~1 + 1))) >> 31) & 1;
    return is0;

}

int conditional(int x, int y, int z) {
    int is0 = !(x ^ 0);
    return ((~is0 + 1) & z) | (~(~is0 + 1) & y);
}

int isPower2(int x) {
    int isMore0 = (x >> 31) & 1;
    int is0 = !(x ^ 0);
    return !isMore0 & !is0 & !(x & (x + (~1 + 1)));
}


int main() {
    printf("Input two numbers for the function bitAnd: ");
    int x, y, res, z;
    scanf("%i %i", &x, &y);
    res = bitAnd(x, y);
    printf("Result: %i \n", res);

    printf("Input two numbers for the function bitXor: ");
    scanf("%i %i", &x, &y);
    res = bitXor(x, y);
    printf("Result: %i \n", res);

    res = thirdBits();
    printf("Result thirdBits: %i \n", res);

    printf("Input two numbers for the function fitsBits: ");
    scanf("%i %i", &x, &y);
    res = fitsBits(x, y);
    printf("Result: %i \n", res);


    printf("Input number for the function sign: ");
    scanf("%i", &x);
    res = sign(x);
    printf("Result: %i \n", res);

    printf("Input one number and n bytes, for the function getByte: ");
    scanf("%i %i", &x, &y);
    res = getByte(x, y);
    printf("Result: %i \n", res);

    printf("Input one number and n shift, for the function logicalShift: ");
    scanf("%i %i", &x, &y);
    res = logicalShift(x, y);
    printf("Result: %i \n", res);

    printf("Input two number for the function addOK: ");
    scanf("%i %i", &x, &y);
    res = addOK(x, y);
    printf("Result: %i \n", res);

    printf("Input number for the function bang: ");
    scanf("%i", &x);
    res = bang(x);
    printf("Result: %i \n", res);

    printf("Input three number for the function conditional: ");
    scanf("%i" "%i" "%i", &x, &y, &z);
    res = conditional(x, y, z);
    printf("Result: %i \n", res);

    printf("Input number for the function isPower2: ");
    scanf("%i", &z);
    res = isPower2(z);
    printf("Result: %i \n", res);

    return 0;
}
