#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BASE 26
#define BEGIN_LETTER 'a'
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct DANode {
    int base, check;
} DANode;

typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node, *Trie;

int node_cnt = 0;

Node *get_new_node() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    node_cnt += 1;
    return p;
}

void clear(Trie root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

Node *insert(Trie root, const char *str) {
    if (root == NULL) root = get_new_node();
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (p->next[ind] == NULL) p->next[ind] = get_new_node();
        p = p->next[ind];
    }
    p->flag = 1;
    return root;
}

int search(Trie root, const char *str) {
    Node *p = root;
    int i = 0;
    while (p && str[i]) {
        int ind = str[i++] - BEGIN_LETTER;
        p = p->next[ind];
    }
    return (p && p->flag);
}

void get_random_string(char *str) {
    int len = rand() % 10 + 1;
    for (int i = 0; i < len; i++) str[i] = BEGIN_LETTER + rand() % BASE;
    str[len] = 0;
    return ;
}

void output(Trie root, char *str, int level) {
    if (root == NULL) return ;
    str[level] = 0;
    if (root->flag) {
        printf("find word : %s\n", str);
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        str[level] = i + BEGIN_LETTER;
        output(root->next[i], str, level + 1);
    }
    return ;
}

void output_da(DANode *data, char *str, int level, int ind) {
    if (data == NULL) return ;
    str[level] = 0;
    if (data[ind].check < 0) {
        printf("Double Array find word : %s\n", str);
    }
    for (int i = 0; i < BASE; i++) {
        if (abs(data[data[ind].base + i].check) != ind) continue;
        str[level] = i + BEGIN_LETTER;
        output_da(data, str, level + 1, data[ind].base + i);
    }
    return ;
}

int get_base(Node *node, DANode *data) {
    int base = 2, flag = 0;
    while (!flag) {
        flag = 1;
        for (int i = 0; i < BASE; i++) {
            if (node->next[i] == NULL) continue;
            if (data[base + i].check == 0) continue;
            flag = 0;
            break;
        }
        base += (!flag);
    }
    return base;
}

int build(Node *node, DANode *data, int ind) {
    if (node == NULL) return 0;
    if (node->flag) data[ind].check = -data[ind].check;
    int max_ind = ind;
    data[ind].base = get_base(node, data);
    for (int i = 0; i < BASE; i++) {
        if (node->next[i] == NULL) continue;
        data[data[ind].base + i].check = ind;
    }
    for (int i = 0; i < BASE; i++) {
        if (node->next[i] == NULL) continue;
        int temp = build(node->next[i], data, data[ind].base + i);
        max_ind = max(max_ind, temp);
    }
    return max_ind;
}

int main() {
    srand(time(0));
    #define INSERT_CNT 1000
    Trie root = NULL;
    char str[50];
    int word_cnt = 0;
    for (int i = 0; i < INSERT_CNT; i++) {
        get_random_string(str);
        root = insert(root, str);
        word_cnt += strlen(str);
        printf("insert %s to Trie\n", str);
    }
    output(root, str, 0);
    DANode *data = (DANode *)calloc(sizeof(DANode), (INSERT_CNT * 100));
    int da_cnt = build(root, data, 1);
    output_da(data, str, 0, 1);
    printf("storage rate : %lf\n", 1.0 * word_cnt / (1.0 * node_cnt * sizeof(Node)));
    printf("Double Array storage rate : %lf\n", 1.0 * word_cnt / (1.0 * sizeof(DANode) * da_cnt));
    #undef INSERT_CNT 
    system("pause");
    return 0;
}