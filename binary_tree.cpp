/*************************************************************************
	> File Name: binary_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年06月25日 星期一 13时01分04秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;
Node *getNode(int);
void clear(Node *);
void pre_order(Node *);
void in_order(Node *);
void post_order(Node *);
int main(){
    Node *root = getNode(1);
    root->lchild = getNode(2);
    root->rchild = getNode(3);
    root->lchild->lchild = getNode(7);
    root->lchild->rchild = getNode(8);
    root->lchild->rchild->lchild = getNode(9);
    root->rchild->rchild = getNode(4);
    root->rchild->rchild->lchild = getNode(5);
    root->rchild->rchild->rchild = getNode(6);
    pre_order(root); printf("\n");
    in_order(root); printf("\n");
    post_order(root); printf("\n");
}

Node *getNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear(Node *root) {
    if (root == NULL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}
void pre_order(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->key);
    pre_order(root->lchild);
    pre_order(root->rchild);
}
void in_order(Node *root) {
    if (root == NULL) return;
    in_order(root->lchild);
    printf("%d ", root->key);
    in_order(root->rchild);
}
void post_order(Node *root) {
    if (root == NULL) return;
    post_order(root->lchild);
    post_order(root->rchild);
    printf("%d ", root->key);
}
