#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define BASE 26
#define BL 'a'

typedef struct DANode {
    int check;
    int base;
    char* str;
}DANode;
typedef struct Node {
    int flag;
    char* str;
    Node* next[BASE];
}Node;
Node* getNode() {
    return (Node*)calloc(1, sizeof(Node));
}
Node* insert(Node* root, const char* str) {
    if (root == NULL) root = getNode();
    Node* p = root;
    for (int i = 0; str[i]; ++i) {
        if (p->next[str[i] - BL] == NULL)  p->next[str[i] - BL] = getNode();
        p = p->next[str[i] - BL];
    }
    p->flag = 1;
    p->str = strdup(str);
    return root;
}

int get_base(Node* root, DANode* data) {
    int base = 2;
    while (true) {
        int flag = 0;
        for (int i = 0; i < BASE; ++i) {
            if (root->next[i] == NULL) continue;
            if (data[base + i].check == 0) continue;
            flag = 1;
            break;
        }
        if (flag == 0) break;
        base++;
    }
    return base;
}
void build_da(Node* root, DANode* data, int ind) {
    if (root == NULL) return;
    data[ind].base = get_base(root, data);
    if (root->flag) {
        data[ind].check *= -1;
        data[ind].str = strdup(root->str); 
    }
    for (int i = 0; i < BASE; ++i) {
        if (root->next[i]) {
            data[data[ind].base + i].check =  ind;
        }
    }
    for (int i = 0; i < BASE; ++i) {
        if (root->next[i]) {
            build_da(root->next[i], data, data[ind].base + i);
        }
    }
    return;
}

void output(DANode* data,int ind) {
    if (data == NULL) return;
    if (data[ind].check < 0) printf("%s\n", data[ind].str);
    for (int i = 0; i < BASE; ++i) {
        if (abs(data[data[ind].base + i].check) == ind) {
            output(data, data[ind].base + i);
        }
    }
}
int main() {
    Node* root = NULL;
    root = insert(root, "hel");
    root = insert(root, "hea");
    root = insert(root, "hac");
    DANode* data = (DANode*)calloc(10000, sizeof(DANode));
    build_da(root, data, 1);
    output(data, 1);
    system("pause");
    return 0;
}