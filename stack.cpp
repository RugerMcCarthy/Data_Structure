/*************************************************************************
	> File Name: stack.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Jul 2018 11:04:19 AM DST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define data_type int
#define NULL_VALUE 0
//栈适合解决所有完全包含关系的问题
typedef struct Stack {
    data_type *data;
    int top, size;
    
} Stack;

Stack* init(int);
void clear(Stack*);
data_type top(Stack*);
int push(Stack*, data_type);
int pop(Stack*);
int empty(Stack*);

int main(){
    srand(time(0));
    Stack* s = init(20);
    for (int i = 0; i < 20; ++i) {
    int op = rand() % 2, value = rand() % 100;
        switch (op) {
        }
    }
}
Stack* init(int n) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data =  (data_type*)malloc(sizeof(data_type) * n);
    s->size = n;
    s->top = -1;
    return s;
}
void clear(Stack* s) {
    if (s == NULL) return;
    free(s->data);
    free(s);
    return;
}
data_type top(Stack* s) {
    if (empty(s)) return NULL_VALUE;
    return s->data[s->top];
}
int push(Stack* s,data_type value) {
    if (s->top + 1 == s->size) {
        return 0;
    }
    s->top += 1;
    s->data[s->top] = value;
    return 1;
}
int pop(Stack* s) {
    if (empty(s)) return 0;
    s->top -= 1;
    return 1;
}
int empty(Stack* s) {
    return s->top == -1;    
}
