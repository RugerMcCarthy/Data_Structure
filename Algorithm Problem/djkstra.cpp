/*************************************************************************
	> File Name: djkstra.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年06月25日 星期一 10时19分13秒
 ************************************************************************/

#include <stdio.h>
#define INF 0x7fffffff
#define NINF -0xffffffff
#define MAX_N 1000
int MIN(int a, int b) {
    return a > b ? b : a;
}
int main() {
    int n, m;
    while (~scanf("%d %d", &n, &m)) {
        int dis[MAX_N + 5] = {0};
        int vis[MAX_N + 5] = {0};
        int e[MAX_N + 5][MAX_N + 5] = {0};
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j) e[i][j] = 0;
                else e[i][j] = INF;
            }
        }
        for (int i = 0; i < m; ++i) {
            int u, v;
            int len;
            scanf("%d %d %d", &u, &v, &len);
            e[u][v] = e[v][u] = MIN(len, e[u][v]);
        }
        for (int i = 1; i <= n; ++i) {
            dis[i] = e[1][i];
        }
        vis[1] = 1;
        for (int i = 1; i <= n - 1; ++i) {
            int min = INF;
            int pos = 0;
            for (int j = 1; j <= n; ++j) {
                if (!vis[j] && dis[j] < min) {
                    min = dis[j];
                    pos = j;
                }
            }
            vis[pos] = 1;
            for (int j = 1; j <= n; ++j) {
                if (e[pos][j] != INF && dis[pos] + e[pos][j] < dis[j]) {
                    dis[j] = dis[pos] + e[pos][j];
                }
            }
        }
        printf("%d\n", dis[n]);
    }
    return 0;
}
