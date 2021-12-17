/*
При решении задач допустимо использование:
1. Целочисленных констант 0т 0 до 255.
2. Аргументов функций и локальных переменных.
3. Операции : ! ~ & ^ | + << >>
Использование условных операторов, вызовов функций, макросов приведений типов не допускается.
Предполагается, что код будет скомпилирован на машине:
1. С представлением целых в дополнительном коде, int – 32 бита
2. Правый сдвиг - арифметический
Для каждой задачи есть ограничение на количество операций.
Сохранение промежуточного результата (=) не считается операцией.
Задачи совпадают с задачами курса The Hardware / Software Interface с сайта https://coursera.org
*/


#include <assert.h>
#include <stdio.h>
#include <limits.h>


/**
bitAnd - x&y, используя ~ and |
Пример: bitAnd (6, 5) = 4
Допустимые операции: ~ |
Предел операций: 8
*/
int bitAnd(int x, int y) {
    return ~(~x | ~y);
}


/**
bitXor - x^y, используя ~ and &
Пример: bitXor (4, 5) = 1
Допустимые операции: ~ &
Предел операций: 14
*/
int bitXor(int x, int y) {
    return ~(x & y) & ~(~x & ~y);
}


/**
thirdBits – возвращает int, каждый третий бит которого, считая с младшего, 1, остальные биты 0.
Допустимые операции: ! ~ & ^ | + << >>
Предел операций: 8
*/
int thirdBits(void) {
    // 0b 00100100 10010010 01001001 00100100
    //          36      146       73       36
    return (36 << 24) | (146 << 16) | (73 << 8) | 36;
}


/**
fitsBits – возвращает 1, если x может быть представлен на машине с n - разрядами ( доп. код )
1 <= n <= 32
Пример: fitsBits (5,3) = 0, fitsBits ( - 4,3) = 1
Допустимые операции : ! ~ & ^ | + << >>
Предел операций : 15
*/
int fitsBits(int x, int n) {
    int minus_one = ~1 + 1;
    x >>= n + minus_one;
    return !x | !(x ^ minus_one);    //| !(((x | minus_one) >> 31) & 1);
}


/**
sign – возвращает 1 , 0 и - 1, если x > 0, x == 0, x < 0 соответственно
Пример: sign(130) = 1
        sign(-23) = - 1
Допустимые операции : ! ~ & ^ | + << >>
Предел операций : 10
*/
int sign(int x) {
//    return !(x >> 31) + (~((~x + 1) >> 31));    // (x > 0) - (-x > 0)
    return !!x | x >> 31;
}


/**
getByte – извлекает n - ый байт из x
Нумерация с 0 ( младший ) to 3 ( старший )+
Пример : getByte (0x12345678,1) = 0x56
Допустимые операции : ! ~ & ^ | + << >>
Предел операций : 6
*/
int getByte(int x, int n) {
//    return (int) (unsigned int)(x << ((4 + ~n) << 3)) >> 24;
    return (x >> (n << 3)) & 0xff;
}


/**
logicalShift – сдвигает биты x вправо по правилам логического сдвига 0 <= n <= 31
Пример: logicalShift (0x87654321, 4) = 0x08765432
Допустимые операции : ~ & ^ | + << >>
Предел операций : 20
*/
int logicalShift(int x, int n) {
    return (int) ((unsigned int) x >> n);
}


/**
addOK – проверяет, может ли x + y быть вычислено без переполнения
Пример: addOK(0x80000000, 0x80000000) = 0,
        addOK(0x80000000, 0x70000000) = 1,
Допустимые операции : ! ~ & ^ | + << >>
Предел операций : 20
 */
int addOK(int x, int y) {
    int sum_sign_bit = (unsigned int) (x + y) >> 31;
    int x_sign_bit = (unsigned int) x >> 31;
    int y_sign_bit = (unsigned int) y >> 31;
//    return (x_sign_bit ^ y_sign_bit) | ((x_sign_bit & y_sign_bit) & sum_sign_bit) | ((!x_sign_bit & !y_sign_bit) & !sum_sign_bit);
    return (x_sign_bit ^ y_sign_bit) | !(x_sign_bit ^ sum_sign_bit);    // | !(y_sign_bit ^ sum_sign_bit);
}


/**
bang – Вычисляет ! x без использования !
Пример: bang (3) = 0, bang (0) = 1
Допустимые операции : ~ & ^ | + << >>
Предел операций: 12
*/
int bang(int x) {
    return ((x | (~x + 1)) >> 31) + 1;
}


/**
conditional – аналог тернарного оператора x ? y : z
Пример: conditional(2, 4, 5) = 4
Допустимые операции : ! ~ & ^ | + << >>
Предел операций: 16
*/
int conditional(int x, int y, int z) {
    int minus_one = ~1 + 1;
    int x_is_zero = !(((x | (~x + 1)) >> 31) & 1);
    return ((x_is_zero + minus_one) & y) | ((!x_is_zero + minus_one) & z);
}


/**e
isPower2 - возвращает 1 , если x – степень 2, иначе 0
Примеры : isPower 2(5) = 0, isPower 2(8) = 1, isPower 2(0) = 0
Отрицательные числа не являются степенью двойки .
Допустимые операции : ! ~ & ^ | + << >>
Предел операций: 20
*/
int isPower2(int x) {
    return !(x >> 31 & 1) & !!x & !(x & (x + ~0));
}


int main() {
    assert(bitAnd(0b1100, 0b1010) == 0b1000);

    assert(bitXor(0b1100, 0b1010) == 0b0110);

    assert(getByte(0x12345678, 1) == 0x56);
    assert(getByte(0xfedcba98, 3) == 0xfe);

    assert(sign(10) == 1);
    assert(sign(0) == 0);
    assert(sign(-10) == -1);

    assert(isPower2(25) == 0);
    assert(isPower2(-25) == 0);
    assert(isPower2(64) == 1);
    assert(isPower2(-64) == 0);
    assert(isPower2(48) == 0);
    assert(isPower2(-48) == 0);
    assert(isPower2(0) == 0);
    assert(isPower2(INT_MAX) == 0);
    assert(isPower2(INT_MIN) == 0);

    assert(thirdBits() == 613566756);

    assert(logicalShift(0x87654321, 4) == 0x8765432);
    assert(logicalShift(0x87654321, 10) == 0x21d950);

    assert(addOK(0x80000000, 0x80000000) == 0);
    assert(addOK(0x80000000, 0x70000000) == 1);
    assert(addOK(0x70000000, 0x70000000) == 0);

    assert(fitsBits(24, 6) == 1);
    assert(fitsBits(16, 5) == 0);
    assert(fitsBits(-8, 4) == 1);
    assert(fitsBits(-10, 3) == 0);

    assert(bang(INT_MAX) == 0);
    assert(bang(3) == 0);
    assert(bang(0) == 1);
    assert(bang(-3) == 0);
    assert(bang(INT_MIN) == 0);

    assert(conditional(2, 3, 4) == 3);
    assert(conditional(0, 5, 6) == 6);
    assert(conditional(-3, 7, 8) == 7);
}
