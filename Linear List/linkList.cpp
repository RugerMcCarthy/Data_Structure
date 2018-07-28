/*************************************************************************
	> File Name: linkList.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  6/ 6 18:14:19 2018
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct LinkList {
    LinkNode *head;
    int n;
} LinkList;

LinkList* init() {
    LinkList *p = (LinkList*)malloc(sizeof(LinkList));
    p->head = NULL;
    p->n = 0;
    return p;
} 


LinkNode* getNewNode(int data) {
    LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
    p->data = data;
    p->next = NULL;
    return p;
}
void clear(LinkList* l) {
    LinkNode* head = l->head;
    while (head) {
        LinkNode *next = head->next;
        free(head);
        head = next;
    }
    free(l);
    return;
}
int insert(LinkList* l, int data, int ind) {
    if (ind < 0) return 0;
    LinkNode ret, *p;
    ret.next = l->head;
    p = &ret;
    while (p && ind--) {
        p = p->next;
    }
    if (p == NULL) return 0;
    LinkNode* new_node = getNewNode(data);
    new_node->next = p->next;
    p->next = new_node;
    l->head = ret.next;
    l->n += 1;
    return 1;
}
void output(LinkList* l) {
    LinkNode* head = l->head;
    while (head) {
        printf("%d ->", head->data);
        head = head->next;
    }
    printf("null\n");
}
int main(){
    LinkList* l = init();
    srand(time(0));
    for (int i = 0; i < 10; ++i) {
        int data = rand() % 100, ind = rand() % (i + 1);
        printf("%d : insert(%d, %d) = ", i, data, ind);
        fflush(stdout);
        insert(l, data, ind);
        output(l);
    }
    clear(l);
    return 0;
}
