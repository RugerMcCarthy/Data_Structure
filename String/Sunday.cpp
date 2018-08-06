#include <stdio.h>
#include <string.h>

#define TEST(func) { \
    printf("%s = %d\n", #func, func); \
}

int sunday(const char *text, const char *pattern) {
    int len_text = strlen(text);
    int len_pat = strlen(pattern);
    int ind[127] = {0};
    for (int i = 0; i < 127; ++i) {
        ind[i] = len_text + 1;
    }
    for (int i = 0; pattern[i]; ++i) {
        ind[pattern[i]] = len_pat - i;
    }
    for (int i = 0; i <= len_text - len_pat;) {
        int j = 0;
        for (;j < len_pat; ++j) {
            if (text[i] != pattern[i]) break;
        }
        if (j == len_pat) return 1;
        i += ind[text[i + len_pat]];
    }
    return 0;
    /*int len = strlen(pattern), len2 = strlen(text);
    int ind[127] = {0};
    for (int i = 0; i < 127; i++) ind[i] = len + 1;
    for (int i = 0; pattern[i]; i++) ind[pattern[i]] = len - i;
    for (int i = 0; i <= len2 - len;) {
        int j = 0;
        for (; j < len; j++) {
            if (pattern[j] != text[i + j]) break;
        }
        if (j == len) return 1;
        i += ind[text[i + len]];
    }
    return 0;*/
}


int main() {
    TEST(sunday("hello world", "hello"))
    return 0;
}