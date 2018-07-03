/*************************************************************************
	> File Name: vector.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  6/ 4 19:54:32 2018
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define malloc2 my_malloc(size, __FILE__, __func__, __LINE__) 

void* my_malloc(size,const char* file, const char* func, int line)
{
    void *data = malloc(size);
    if (data == NULL) {
        fprintf(stderr,"[%s : %s : %s] malloc error\n", file, func, line);
        fflush(stderr);
        abort();
    }
    return data;
}

typedef struct Vector { 
    int *data;
    int size, length;
    
}Vector;

Vector* init(int n) {
    Vector *p = (Vector*)malloc(sizeof(Vector));
    p->data = (int*)malloc(sizeof(int) * n);
    p->size = n;
    p->length = 0;
    return p;
}

int expand(Vector* v){
    int new_size = v->size;
    while (new_size){
        int *data = (int *)realloc(v->data, sizeof(int) * (v->size + new_size));
        if (data == NULL) {
            new_size /= 2;
            continue;
        }
        break;
    }
    printf("%d\n");
    return 1;
}
int insert(Vector* v, int x, int ind) {
    if (v->length >= v->size) {
        if (!expand(v)) {
            return 0;
        }
        return 0;
    }
    if (ind < 0 || ind > v->length) {
        return 0;
    }
    for (int i = v->length - 1; i >= ind ; --i) {
        v->data[i + 1] = v->data[i];
    }
    v->data[ind] = x;
    v->length += 1;
    return 1;
}

int delete_element(Vector *v, int ind){
    if (ind >= v->length || ind < 0) {
        return 0;
    }
    for (int i = ind + 1; i < v->length; ++i) {
        v->data[i - 1] = v->data[i];
    }
    v->length -= 1;
    return 1;
}

void output(Vector* v) {
    printf("[ ");
    for (int i = 0; i < v->length; ++i) {
        printf(" %d", v->data[i]);
    }
    printf(" ]");
    printf("\n");
}

void clear(Vector* v) {
    if (v == NULL) return;
    free(v->data);
    free(v);
    return;
}

int main() {
    srand(time(0));
    Vector *v = NULL;
    v = init(100);
    for (int i = 0; i < 10; ++i) {
        int x = rand() % 100, ind = rand() % (i + 1);
        printf("insert(%d, %d)", x, ind);
        insert(v, x, ind);
        output(v);
    }
    printf("\n");
    for (int i = 0; i < 10; ++i) {
        int ind = rand() % (v->length + 2) - 1;
        printf("delete_element(%d) = ", ind);
        int ret = delete_element(v, ind);
        printf("%d : ", ret);
        output(v);
    }
    return 0;
}
