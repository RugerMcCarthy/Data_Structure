/*************************************************************************
	> File Name: heap.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年06月25日 星期一 18时38分06秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef struct Heap {
    int *data;
    int n, size;
} Heap;

Heap *init(int n);
void clear(Heap *);
void push(Heap *, int);
void pop(Heap *);
void output(Heap *);
int main(){
    srand(time(0));
    Heap *p = init(21);
    for (int i = 0; i < 20; ++i) {
        int value = rand() % 100;
        printf("insert %d to heap\n", value);
        push(p, value);
        output(p);
    }
    for (int i = 0; i < 20; ++i) {
        pop(p);
        output(p);   
    }
    clear(p);
    return 0;
}

Heap * init(int n) {
    Heap *p = (Heap *)malloc(sizeof(Heap));
    p->data = (int *)malloc(sizeof(int) * n);
    memset(p->data, 0 , sizeof(p->data));
    p->size = n;
    p->n = 0;
    return p;
}

void clear(Heap *h) {
    if (h == NULL) return;
    free(h->data);
    free(h);
    return;
}

void push(Heap *h, int value) {
    if (h->n == h->size) return;
    h->n += 1;
    h->data[h->n] = value;
    int i = h->n;
    while (i > 1) {
        if (h->data[i] <= h->data[i / 2]) break;
        h->data[i] ^= h->data[i / 2];
        h->data[i / 2] ^= h->data[i];
        h->data[i] ^= h->data[i / 2];
        i /= 2;
    }
    return ;
}
void pop(Heap *h) {
    if (h->n <= 1) {
        h->n = 0;
        return;
    }
    h->data[1] ^= h->data[h->n];
    h->data[h->n] ^= h->data[1];
    h->data[1] ^= h->data[h->n];
    h->n -= 1;
    int ind = 1;
    while (ind * 2 <= h->n) {
        int swap_ind = ind * 2;
        if (h->data[ind * 2] > h->data[swap_ind]) swap_ind = ind * 2;
        if (ind * 2 + 1 <= h->n && h->data[ind * 2 + 1] > h->data[swap_ind])
            swap_ind = ind * 2 + 1;
        if (swap_ind == ind) break;
        h->data[ind] ^= h->data[swap_ind];
        h->data[swap_ind] ^= h->data[ind];
        h->data[ind] ^= h->data[swap_ind];
        ind = swap_ind;
    }
    return;
}

void output(Heap *h) {
    printf("Heap = [");
    for (int i = 1; i < h->size; ++i) {
        printf("%d, ", h->data[i]);
    }
    printf("]\n");
    return;
}
