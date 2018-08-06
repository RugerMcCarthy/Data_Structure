#include <stdio.h>
#include <stdlib.h>
int main() {
    int sum3 = (3 + (1000 / 3) * 3) * 333 / 2;
    int sum5 = (5 + (1000 / 5) * 5) * 199 / 2;
    int sum15 = (15 + (1000 / 15) * 15) * 66 / 2;
    printf("%d\n", sum3 + sum5 - sum15);
    system("pause");
    return 0;
}

/*int main() {
    int year, month, day;
    while (~scanf("%d/%d/%d", &year, &month, &day)) {
        int flag = 0;
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) flag = 1;
        int MONGTH[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (flag) MONGTH[2] = 29;
        int ans = 0;
        for (int i = month - 1; i >= 1; --i) {
            ans += MONGTH[i];
        }
        ans += day;
        printf("%d\n", ans);
    }
}*/


/*int main() {
    int n;
    while (~scanf("%d", &n)) {
        int nums[1024] = {0};
        while (n) {
            if (n % 2 == 1) {
                nums[++nums[0]] = 1;
            }else {
                nums[++nums[0]] = 0;
            }
            n /= 2;
        }
        for (int i = nums[0]; i >= 1; --i) {
            printf("%d", nums[i]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}*/