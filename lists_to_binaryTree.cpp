#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    char key;
    struct Node *lchild, *rchild;
} Node;

Node *getNode(char ch){
    Node *p = (Node*)malloc(sizeof(Node));
    p->key = ch;
    p->lchild = p->rchild = NULL;
    return p;
}
Node* build(char *str, Node* root, int init) {
    if (*str == 0) return NULL;
    static int i;
    if (init) i = 0;
    Node* p = NULL; int flag = 0;
    while (str[i]) {
        switch (str[i]) {
            case '(':{
                i += 1;
                p = build(str, p, 0);
            }break;
            case ')':{
                i += 1;
                if (root == NULL) return p;
                return root;
            }
            case ',': {
                i += 1;
                flag = 1;
            }break;
            case ' ': {
                i += 1;
                break;
            }
            default: {
                p = getNode(str[i]);
                i += 1;
                if (root != NULL) {
                    if (flag == 0) {
                        root->lchild = p;
                    } else {
                        root->rchild = p;
                    }
                }
            } break;
        }
    }
    return root? root:p;
}
void output(Node *root) {
    if (root == NULL) return;
    output(root->lchild);
    printf("%c ", root->key);
    output(root->rchild);
    return;
}
int main(){
    char str[1005];
    while (~scanf("%[^\n]s", str)) {
        getchar();
        Node* p = build(str, NULL, 1);
        output(p);
        printf("\n");
    }
    return 0;
}
