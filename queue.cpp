/*************************************************************************
	> File Name: queue.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Jul 2018 09:45:37 AM DST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define data_type int
#define NULL_VALUE -16384


typedef struct Queue {
        data_type *data;
        int head, tail;
        int length;
        int count;
} Queue;

Queue *init(int n);
void clear(Queue *);
data_type front(Queue *);
int push(Queue *, data_type);
int pop(Queue *);
int empty(Queue *);

void output(Queue *q) {
        printf("[");
        for (int i = 0, head = q->head; 
                     i < q->count; 
             i++, head = (head + 1) % q->length) {
                         printf("%d, ", q->data[head]);
                     
             }
        printf("]\n");
        return ;
}

int main() {
        srand(time(0));
        Queue *q = init(10);
    for (int i = 0; i < 20; i++) {
                int op = rand() % 2, value = rand() % 100;
        if (op == 1) {
                        printf("insert %d to queue\n", value);
                        push(q, value);
                        output(q);
                    
        } else {
                        printf("pop element from queue = %d\n", pop(q));
                        output(q);
                    
        }
            
    }
        return 0;

}

Queue *init(int n) {
        Queue *q = (Queue *)malloc(sizeof(Queue));
        q->data = (data_type *)malloc(sizeof(data_type) * n);
        q->head = 0;
        q->tail = -1;
        q->count = 0;
        q->length = n;
        return q;

}

void clear(Queue *q) {
        if (q == NULL) return ;
        free(q->data);
        free(q);
        return ;

}

data_type front(Queue *q) {
        if (empty(q)) return NULL_VALUE;
        return q->data[q->head];

}

int push(Queue *q, data_type value) {
        if (q->length == q->count) return 0;
        q->tail = (q->tail + 1) % q->length;
        q->count += 1;
        q->data[q->tail] = value;
        return 1;

}

int pop(Queue *q) {
        if (empty(q)) return 0;
        q->count -= 1;
        q->head = (q->head + 1) % q->length;
        return 1;
}

int empty(Queue *q) {
        return q->count == 0;
}
