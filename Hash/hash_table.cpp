#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct Data {
    char *str;
    struct Data *next;
}Data;

typedef struct HashTable {
    Data *data;
    int size;
    int cnt;
    int (*hash_func)(const char *);
}HashTable;

HashTable* init(int size, int (*func)(const char *)) {
    HashTable *table = (HashTable*)malloc(sizeof(HashTable));
    table->data = (Data*)calloc(size ,sizeof(Data));
    table->cnt = 0;
    table->hash_func = func;
    table->size = size;
    return table;
}

int query(HashTable* table, const char *str) {
    int ind = table->hash_func(str) % table->size;
    Data* p = table->data[ind].next;
    while (p) {
        if (strcmp(p->str, str) == 0) {
            return -1;
        }
        table->cnt++;
        p = p->next;
    }
    return ind;
}

void insert(HashTable* table, const char *str) {
    int ind = query(table, str);
    if (ind == -1) return;
    Data* node = (Data*)malloc(sizeof(Data));
    node->str = strdup(str);
    node->next = table->data[ind].next;
    table->data[ind].next = node;
    return;
}



int APHash(const char *str) {
    int hash_value = 0;
    for (int i = 0; str[i]; ++i) {
        if (i & 1) {  //变长到定长的输出
            hash_value ^= (hash_value << 7) ^ str[i] ^ (hash_value >> 3);
        }else {
            hash_value ^= (~((hash_value << 11) ^ str[i] ^ (hash_value >> 5)));
        }
    }
    return hash_value & 0x7fffffff;
}
int BKDRHash(const char *str) { //变长到定长的输出
    int hash_value = 0, seed = 131;// prime to 256
    for (int i = 0; str[i]; ++i) {
        hash_value = hash_value * seed + str[i];
    }
    return hash_value & 0x7fffffff;
}

int zobrist_table[50][256] = {0};
void init_zobrist_table() {
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 256; ++j) {
            zobrist_table[i][j] = rand();
        }
    }
    return;
}
int ZobristHash(const char *str) {
    static int flag = 1;
    if (flag) {
        flag = 0;
        init_zobrist_table();
    }
    int hash_value = 0;
    for (int i = 0; str[i]; ++i) {
        hash_value ^= zobrist_table[i][str[i]];
    }
    return hash_value & 0x7fffffff;
}

int MyHash(const char *str) {
    int hash = 1;
    for (int i = 0; str[i]; i++) {
        hash *= str[i];
    }
    return hash & 0x7fffffff;
}

int main() {
    #define HASH_TABLE_SIZE 100000
    HashTable *apHashTable = init(HASH_TABLE_SIZE, APHash);
    HashTable *bkdrHashTable = init(HASH_TABLE_SIZE, BKDRHash);
    HashTable *zobristHashTable = init(HASH_TABLE_SIZE, ZobristHash);
    HashTable *myHashTable = init(HASH_TABLE_SIZE, MyHash);
    #define MAX_TEST_CNT 100000
    for (int i = 0; i < MAX_TEST_CNT; i++) {
        char str[7] = {0};
        for (int j = 0; j < 6; j++) {
            str[j] = rand() % 26 + 'a';
        }
        str[6] = 0;
        insert(apHashTable, str);
        insert(bkdrHashTable, str);
        insert(zobristHashTable, str);
        insert(myHashTable, str);
    }
    printf("APHash(%d) = %d\n", MAX_TEST_CNT, apHashTable->cnt);
    printf("BKDRHash(%d) = %d\n", MAX_TEST_CNT, bkdrHashTable->cnt);
    printf("ZobristHash(%d) = %d\n", MAX_TEST_CNT, zobristHashTable->cnt);
    printf("MyHash(%d) = %d\n", MAX_TEST_CNT, myHashTable->cnt);
    #undef MAX_TEST_CNT
    #undef HASH_TABLE_SIZE
    return 0;
}
