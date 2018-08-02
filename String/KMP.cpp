#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int KMP(const char *text, const char *pattern) {
    int len_1 = strlen(text);
    int len_2 = strlen(pattern);
    int *next = (int *)malloc(sizeof(int) * len_2);
    next[0] = -1;
    int matrix = -1;
    for (int i = 1; pattern[i]; ++i) {
        while (matrix != -1 && pattern[matrix + 1] != pattern[i]) {
            matrix = next[matrix];
        }
        if (pattern[matrix + 1] == pattern[i]) {
            matrix = matrix + 1;
        }
        next[i] = matrix;
    }
    /*for (int i = 0; pattern[i]; ++i) {
        printf("%d ", next[i]);
    }
    printf("\n");*/
    matrix = -1;
    for (int i = 0; text[i]; ++i) {
        while (matrix != -1 && pattern[matrix + 1] != text[i]) {
            matrix = next[matrix];
        }
        if (pattern[matrix + 1] == text[i]) {matrix++;}
        if (pattern[matrix + 1] == 0) return 1;
    }
    return 0;
}
int main() {
    char str[] = "hello world";
    printf("%d\n", KMP(str, "hea"));
    return 0;
}
