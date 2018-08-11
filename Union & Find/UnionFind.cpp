#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct UnionSet {
    int n;
    int cnt;
    int *data;
    int *size;
} UnionSet;

UnionSet* init(int n) {
    UnionSet* u = (UnionSet *)malloc(sizeof(UnionSet));
    u->n = n;
    u->cnt = n;
    u->data = (int *)calloc(n, sizeof(int));
    u->size = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i) {
        u->data[i] = i;
        u->size[i] = 1;
    }
    return u;
}

int find(UnionSet* u, int n) {
    if (n == u->data[n]) return n;
    return u->data[n] = find(u, u->data[n]);
}

int merge(UnionSet* u, int a, int b) {
    int fa = find(u, a);
    int fb = find(u, b);
    if (fa == fb) return 0;
    if (u->size[fa] > u->size[fb]) {
        u->data[fb] = fa;
        u->size[fa] += u->size[fb];
    }else {
        u->data[fa] = fb;
        u->size[fb] += u->size[fa];
    }
    u->cnt--;
    return 1;
}
int main() {
    srand(time(0));
    UnionSet *u = init(10);
    #define OP_NUM 10
        for (int i = 0; i < OP_NUM; ++i) {
            int a = rand() % 10, b = rand() % 10;
            printf("union %d with %d = %d \n", a, b, merge(u, a, b));
            printf("union set count : %d\n", u->cnt);
        }
    #undef OP_NUM
    system("pause");
    return 0;
}