#include <stdio.h>
#include <string.h>

void other() {
    printf("Something is wrong\n");
}

void input() {
    int n;
    int z = 0;
    int list[2];
    while(1) {
        printf("Type the %d number:", z + 1);
        scanf("%d", &n);
        z++;
        if(n == 0) {
            return;
        }
        else {
            list[z] = n;
        }
    }
}

int main() {
    printf("Type address of other() on the sixth number or type 0 if you want to exit\n");
    printf("The address of other() is %d\n", other);
    input();
    printf("It will not be shown\n");

    return 0;
}
