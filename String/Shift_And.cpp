#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BASE 30
#define TEST(func) { \
    printf("%s = %d\n", #func, func); \
}
#define BASE 30

typedef struct BitData {
    int *data;
    int cnt;
} BitData;

BitData *init(int n) {
    BitData *p = (BitData *)malloc(sizeof(BitData));
    p->data = (int *)calloc(sizeof(int), n / BASE + 1);
    p->cnt = n / BASE + 1;
    return p;
}

void clear(BitData *d) {
    if (d == NULL) return ;
    free(d->data);
    free(d);
}

void operator_or(BitData *d, int n) {
    int x = n / BASE;
    int y = n % BASE;
    d->data[x] |= (1 << y);
    return ;
}

void operator_and(BitData *d1, BitData *d2) {
    int len = d1->cnt < d2->cnt ? d1->cnt : d2->cnt;
    for (int i = 0; i < len; i++) {
        d1->data[i] &= d2->data[i];
    }
    for (int i = len; i < d1->cnt; i++) {
        d1->data[i] = 0;
    }
    return ;
}

int operator_get(BitData *d, int n) {
    int x = n / BASE;
    int y = n % BASE;
    return d->data[x] & (1 << y);
}

int operator_left(BitData *d) {
    for (int i = d->cnt - 1; i >= 0; i--) {
        if (i != d->cnt - 1) {
            d->data[i + 1] |= (d->data[i] >> (BASE - 1));
        }
        d->data[i] <<= 1;
    }
    return 0;
}

int Shift_and(const char *text, const char *pattern) {
    BitData *d[127] = {0};
    int n = strlen(pattern);
    for (int i = 0; i < 127; i++) {
        d[i] = init(n);
    }
    for (int i = 0; i < n; i++) {
        operator_or(d[pattern[i]], i);
    }
    BitData *p = init(n);
    for (int i = 0; text[i]; i++) {
        operator_left(p);
        operator_or(p, 0);
        operator_and(p, d[text[i]]);
        if (operator_get(p, n - 1)) return 1;
    }
    return 0;
}

int shift_and(const char *text, const char *pattern) {
    int d[127] = {0}, n = 0;
    for (; pattern[n]; n++) {
        d[pattern[n]] |= (1 << n);
    }
    int p = 0;
    for (int i = 0; text[i]; i++) {
        p = (p << 1 | 1) & d[text[i]];
        if (p & (1 << (n - 1))) return 1;
    }
    return 0;
}

int main() {
    TEST(shift_and("hello world", "wor"))
    TEST(Shift_and("hello world", "old"))
    system("pause");
    return 0;
}