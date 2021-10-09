#include <stdio.h>
#include <ctype.h>


int is_palindrome(char *string, size_t string_len){
    for (int i = 0; i < string_len / 2; i++){
        if (tolower(string[i]) != tolower(string[string_len - i - 1]))
            return 0;
    }
    return 1;
}

int main(){
    char *string = NULL;
    size_t buf_len = 100,
           string_len;

    printf("Enter string >>> ");
    string_len = getline(&string, &buf_len, stdin) - 1;

    if (is_palindrome(string, string_len))
        printf("Palindrome");
    else
        printf("Not palindrome");

}