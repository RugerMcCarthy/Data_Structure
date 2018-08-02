#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int BF(const char *text, const char *pattern) {
    int len1 = strlen(text);
    int len2 = strlen(pattern);
    for (int i = 0; i < len1 - len2 + 1; ++i) {
        int flag = 1;
        for (int j = 0; pattern[j]; ++j) {
            if (text[i + j] == pattern[j]) continue;
            flag = 0;
        }
        if (flag) return 1;
    }
    return 0;
}

int main() {
    char str[] = "hello world";
    printf("%d\n", BF(str, "he"));
    return 0;
}
