#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int min(int a, int b) {
    return (a <= b) ? a : b;
}


/// https://ru.wikipedia.org/wiki/Z-функция
int *z_function(const char *string, size_t string_len) {
    int left = 0;
    int right = 0;
    int *z_func = (int *) malloc(sizeof(int) * string_len);
    for (int i = 0; i < string_len; i++) {
        z_func[i] = 0;
    }

    for (int i = 1; i < string_len; i++) {
        if (i < right) {
            z_func[i] = min(right - i + 1, z_func[i - left]);
        }
        while (i + z_func[i] < string_len && string[z_func[i]] == string[i + z_func[i]]) {
            z_func[i] += 1;
        }
        if (i + z_func[i] - 1 > right) {
            left = i;
            right = left + z_func[i] - 1;
        }
    }

    return z_func;
}


int count_substrings(char *string, size_t string_len, char *substring, size_t substring_len) {
    if (substring_len == 0) {
        return 0;
    }

    size_t concat_len = string_len + substring_len + 1;
    char concat[concat_len];
    strncpy(concat, substring, substring_len + 1);
//    strcpy(concat + substring_len, "\000");
    strncpy(concat + substring_len + 1, string, string_len);

    int count = 0;
    int *z_function_results = z_function(concat, concat_len);
    for (size_t i = substring_len + 1; i < concat_len; i++) {
        if (z_function_results[i] >= substring_len) {
            count++;
        }
    }

    free(z_function_results);
    return count;
}


int main() {
    char *string = NULL, *substring = NULL;
    size_t buf_len = 100, string_len, substring_len;

    printf("Enter string >>> ");
    string_len = getline(&string, &buf_len, stdin) - 1;
    printf("Enter substring >>> ");
    substring_len = getline(&substring, &buf_len, stdin) - 1;

    int c = count_substrings(string, string_len, substring, substring_len);
    printf("Number of substrings in string = %d\n", c);

    free(string);
    free(substring);
}
