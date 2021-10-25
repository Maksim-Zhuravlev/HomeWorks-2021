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


#include <stdio.h>


/**
bitAnd - x&y, используя ~ and |
Пример: bitAnd (6, 5) = 4
Допустимые операции: ~ |
Предел операций: 8
*/
int bit_and(int x, int y) {
    return ~(~x | ~y);
}


/**
bitXor - x^y, используя ~ and &
Пример: bitXor (4, 5) = 1
Допустимые операции: ~ &
Предел операций: 14
*/
int bit_xor(int x, int y) {
    return ~(x & y) & ~(~x & ~y);
}


/**
thirdBits – возвращает int, каждый третий бит которого, считая с младшего, 1, остальные биты 0.
Допустимые операции: ! ~ & ^ | + << >>
Предел операций: 8
*/
int third_bits(void) {
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
int fits_bits(int x, int n) {
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
int get_byte(int x, int n) {
    return (int)((unsigned int)x << ((4 + ~n) << 3)) >> 24;
}


/**
logicalShift – сдвигает биты x вправо по правилам логического сдвига 0 <= n <= 31
Пример: logicalShift (0x87654321, 4) = 0x08765432
Допустимые операции : ~ & ^ | + << >>
Предел операций : 20
*/
int logical_shift(int x, int n) {
    return (int)((unsigned int)x >> n);
}


/**
addOK – проверяет, может ли x + y быть вычислено без переполнения
Пример: addOK(0x80000000, 0x80000000) = 0,
        addOK(0x80000000, 0x70000000) = 1,
Допустимые операции : ! ~ & ^ | + << >>
Предел операций : 20
 */
int add_ok(int x, int y){
    int sum_sign_bit = (unsigned int)(x + y) >> 31,
        x_sign_bit = (unsigned int)x >> 31,
        y_sign_bit = (unsigned int)y >> 31;
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
    return ((x | (~x + 1)) >> 31) & 1;
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


/**
isPower 2 - возвращает 1 , если x – степень 2, иначе 0
Примеры : isPower 2(5) = 0, isPower 2(8) = 1, isPower 2(0) = 0
Отрицательные числа не являются степенью двойки .
Допустимые операции : ! ~ & ^ | + << >>
Предел операций: 20
*/
int is_power2(int x) {
    return !(x & (x + ~0));
}


int main(){

    printf("bit_and(0b1100, 0b1010) = %d\n",bit_and(0b1100, 0b1010));

    printf("bit_xor(0b1100, 0b1010) = %d\n", bit_xor(0b1100, 0b1010));

    printf("get_byte(0x12345678, 1) = 0x%x\n"
           "get_byte(0xfedcba98, 1) = 0x%x\n",
            get_byte(0x12345678,1),
            get_byte(0xfedcba98,3)
            );

    printf("sign(10) = %d\n"
           "sign(0) = %d\n"
           "sign(-10) =  %d\n",
           sign(10),
           sign(0),
           sign(-10)
           );

    printf("is_power2(25) = %d\n"
           "is_power2(-25) = %d\n"
           "is_power2(64) =  %d\n"
           "is_power2(-64) =  %d\n"
           "is_power2(48) =  %d\n"
           "is_power2(-48) =  %d\n"
           "is_power2(0) =  %d\n",
           is_power2(25),
           is_power2(-25),
           is_power2(64),
           is_power2(-64),
           is_power2(48),
           is_power2(-48),
           is_power2(0)
           );

    printf("third_bits() = %d\n", third_bits());

    printf("logical_shift (0x87654321, 4) = 0x%d\n", logical_shift (0x87654321, 4));

    printf("add_ok(0x80000000, 0x80000000) = %d\n"
           "add_ok(0x80000000, 0x70000000) = %d\n"
           "add_ok(0x70000000, 0x70000000) = %d\n",
           add_ok(0x80000000, 0x80000000),
           add_ok(0x80000000, 0x70000000),
           add_ok(0x70000000, 0x70000000)
           );

    printf("fits_bits (24, 6) = %d\n"
           "fits_bits (16, 5) = %d\n"
           "fits_bits (-8, 4) = %d\n"
           "fits_bits (-10, 3) = %d\n",
           fits_bits (24, 6),
           fits_bits (16, 5),
           fits_bits (-8, 4),
           fits_bits (-10, 3)
           );

    printf("bang (3) = %d\n"
           "bang (0) = %d\n"
           "bang (-3) = %d\n",
           bang (3),
           bang (0),
           bang (-3)
           );

    printf("conditional(2, 3, 4) = %d\n"
           "conditional(0, 5, 6) = %d\n"
           "conditional(-3, 7, 8) = %d\n",
           conditional(2, 3, 4),
           conditional(0, 5, 6),
           conditional(-3, 7, 8)
           );
}