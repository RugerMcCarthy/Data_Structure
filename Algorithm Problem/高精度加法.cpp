/*************************************************************************
	> File Name: BigNumAdd.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  6/29 10:56:04 2018
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#define N 1024
char* BigNumAdd(char *a, char* b) {
    int ans_n[N + 5] = {0};
    char ans[N + 5] = {0};
    int len_a = strlen(a);
    int len_b = strlen(b);
    for (int i = 0; a[i]; ++i) {
        ans_n[len_a - i] = (a[i] - '0');
    }
    for (int i = 0; b[i]; ++i) {
        ans_n[len_b - i] += (b[i] - '0');
    }
    ans_n[0] = len_a > len_b ? len_a : len_b;
    for (int i = 1; i <= ans_n[0]; ++i) {
        if (ans_n[i] < 10) {
            continue;
        }
        ans_n[i + 1] += (ans_n[i] / 10);
        ans_n[i] %= 10;
        ans_n[0] += (i == ans_n[0]);
    }
    for (int i = ans_n[0]; i >= 1; --i) {
        ans[ans_n[0] - i] = ans_n[i] + '0';
    }
    return ans;
}

int main(){
    char a[N] = {0}, b[N] = {0};
    while (scanf("%s %s", a, b)) {
        char *p = BigNumAdd(a, b);
        printf("%s\n", p);
    }
}
