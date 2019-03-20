#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int max(int a, int b) {
    return a > b ? a : b;
}
char* sum(char* a, char* b) {
    int lena = strlen(a);
    int lenb = strlen(b);
    int max_len = max(lena, lenb);
    int* ans = (int*)calloc(max_len + 2, sizeof(int));
    char* nums = (char*)calloc(max_len, sizeof(char));
    ///昨天的问题在这里没有处理好
    ///解决方案是用两个变量记录两个数字的最低位，然后向前拓展
    int ind_a = lena - 1;
    int ind_b = lenb - 1;
    while (ind_a >= 0 && ind_b >= 0) {
        ans[++ans[0]] = (a[ind_a--] - '0') + (b[ind_b--] - '0');
    }
    while (ind_a >= 0) {
        ans[++ans[0]] = a[ind_a--] - '0';
    }
    while (ind_b >= 0) {
        ans[++ans[0]] = b[ind_b--] - '0';
    }
    for (int i = 1; i <= ans[0]; ++i) {
        if (ans[i] < 10) continue;///当前位如果小于10则不进位
        ans[i + 1] += (ans[i] / 10);///向前进位
        ans[i] %= 10;///当前位存放进位数字
        ans[0] += (i == ans[0]);///如果已经到达最高位，发现还需要进位。然后答案长度加一。这么写可以减少一个if，使得代码逻辑紧凑
    }
    for (int i = ans[0]; i >= 1; i--) {
        nums[ans[0] - i] = (ans[i] + '0');
    }
    nums[ans[0]] = 0;///虽然calloc申请的内存。保险起见末尾还是添加个'\0'
    free(ans);
    return nums;
}
int main() {
    char a[100005] = {0};
    char b[100005] = {0};
    while (~scanf("%s %s", a, b)) {
        char* ans = sum(a, b);
        printf("%s\n", ans);
    }

}