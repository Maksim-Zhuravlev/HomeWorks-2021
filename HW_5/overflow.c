#include <stdio.h>


size_t before_input_call, after_input_call;

void other() {
    printf("\n========== other ==========\n");
    size_t data[0];
    data[1] = after_input_call;
}

void input(int a, int b, int c, int d, int e, int f, int g, int h) {
    size_t data[2];
    printf("\n========== input ==========\n");
    printf("%p EBP = %p\n%p Return pointer = %p (%zu)\nparameters passed with stack %zu, %zu\n\n>>> ",
           &data[2], data[2], &data[3], (int *) data[3], data[3], data[4], data[5]);
    scanf("%zu", &data[3]);
}

int main() {
    before_input_call = &&before_input_call;
    after_input_call = &&after_input_call;
    printf("%p (%zu) before input call\n", &&before_input_call, &&before_input_call);
    printf("%p (%zu) after input call\n", &&after_input_call, &&after_input_call);
    printf("%p (%zu) other\n", &other, &other);

    before_input_call:
    input(1,2,3,4,5,6,7,8);
    after_input_call:
    printf("\n========== end of main ==========\n");
}
