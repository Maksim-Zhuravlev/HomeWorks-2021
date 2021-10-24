/*
2. Реализовать функцию
int div(int divisor, int dividend) {
    return divisor / dividend;
}
, заменив деление на собственную реализацию без использования указанной операции.
Если результат не представим в int, то возвращать 0.
Подсказки:
- среди входных значений для тестирования будет INT_MIN_VALUE,
- будут все комбинации знаков делителя и делимого,
- существуют решения более быстрые и изящные, чем вычитание в цикле.
 */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int div_(int dividend_, int divisor_) {
    int answer = 0;
    unsigned int accumulator = 0;
    int sign = (dividend_ < 0) ^ (divisor_ < 0) ? -1 : 1;

    unsigned int dividend = abs(dividend_);
    unsigned int divisor = abs(divisor_);


    for (int i = 31; i >= 0; i--) {
        if ((divisor << i) > 0 && accumulator + (divisor << i) <= dividend) {
            answer |= 1 << i;
            accumulator += divisor << i;
        }
    }
    if (answer == INT_MIN && sign == 1) return 0;
    return accumulator == dividend ? answer * sign : 0;
}


int main() {
    int a, b;

    printf("1 / 0 = %d\n"
           "16 / 4 = %d\n"
           "16 / 3 = %d\n"
           "21 / 4 = %d\n"
           "21 / 3 = %d\n"
           "INT_MIN / -1 = %d\n"
           "INT_MIN / 1 = %d\n"
           "INT_MIN / INT_MIN = %d\n",
           div_(1, 0),
           div_(16, 4),
           div_(16, 3),
           div_(21, 2),
           div_(21, 3),
           div_(INT_MIN, -1),
           div_(INT_MIN, 1),
           div_(INT_MIN, INT_MIN)
    );

    int i = 10;
    while (i--) {
        printf("a, b = ");
        scanf("%d %d", &a, &b);
        printf("%d\n", div_(a, b));
    }
}