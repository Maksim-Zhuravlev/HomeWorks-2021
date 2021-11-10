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
#include <assert.h>


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
    if (answer == INT_MIN && sign == 1) {
        return 0;
    }

    return accumulator == dividend ? answer * sign : 0;
}


int main() {
    assert(div_(1, 0) == 0);
    assert(div_(16, 4) == 4);
    assert(div_(16, 3) == 0);
    assert(div_(21, 2) == 0);
    assert(div_(21, 3) == 7);
    assert(div_(INT_MIN, -1) == 0);
    assert(div_(INT_MIN, 1) == -2147483648);
    assert(div_(INT_MIN, INT_MIN) == 1);

    int i = 10;
    int a, b;
    while (i--) {
        printf("a, b = ");
        scanf("%d %d", &a, &b);
        printf("%d\n", div_(a, b));
    }
}