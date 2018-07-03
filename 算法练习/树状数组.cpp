/*************************************************************************
	> File Name: tree_arr.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/30 23:08:04 2018
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_N 100005
int n, m;
int c[MAX_N] = {0};
int num[MAX_N] = {0};
int lowbit(int x) {
    return x & (-x);
}
void update(int i, int x) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
}
int sum(int i) {
    int sum = 0;
    while (i > 0) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}
int getSum(int u, int v) {
    return sum(v) - sum(u - 1);
}
int main(){
    while (~scanf("%d %d", &n, &m)) {
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &num[i]);
            update(i, num[i]);
        }
        getchar();
        for (int i = 1; i <= m; ++i) {
            char command;
            scanf("%c", &command);
            if (command == 'Q') {
                int u,v;
                scanf("%d %d", &u, &v);
                printf("%d\n",getSum(u,v));
            } else if (command == 'C') {
                int u,v,val;
                scanf("%d %d %d", &u, &v, &val);
                for (int j = u; j <= v; ++j) {
                    update(j, val);
                }
            }
            getchar();
        }
    }
    return 0;
}
