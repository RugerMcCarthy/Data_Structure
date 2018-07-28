#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define lowbit(x) (x & 0xffff)
#define highbit(x) ((x >> 16) & 0xffff)
#define SWAP(a, b) {\
    __typeof(a) temp = a;\
    a = b;\
    b = temp;\
}

void insert_sort(int *, int);
void bubble_sort(int *, int);
void merge_sort(int *, int, int);
void raddix_sort(int *, int);

void output(int *num, int n) {
    printf("[");
    for (int i = 0; i < n; ++i) {
        printf("%d ", num[i]);
    }
    printf("]\n");
}


int main() {
    srand(time(0));
    int num[30] = {0};
    printf("[");
    for (int i = 0; i < 30; ++i) {
        num[i] = rand() % 100;
        printf("%d ", num[i]);
    }
    printf("]\n");
    raddix_sort(num, 30);
    output(num, 30);
    return 0;
}

void insert_sort(int *num, int n) {
    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; j--) {
            if (num[j + 1] >= num[j]) break;
            SWAP(num[j], num[j + 1]);
        }
    }
    return ;
}
void bubble_sort(int *num, int n) {
    int flag;
    for (int i = 0; i < n; ++i) {
        flag = 0;
        for (int j = 0; j < n - i; ++j) {
            if (num[j] <= num[j + 1]) continue;
            SWAP(num[j], num[j + 1]);
            flag += 1;
        }
        if (flag == 0) break;
    }
    return;
}
void merge_sort(int *num, int l, int r) {
    if (r - l < 16) {
        insert_sort(num + l, r - l + 1);
        return;
    }
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *temp =(int*)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 <= r) {
        if (p1 <= mid && (num[p1] <= num[p2] || p2 > r)) {
            temp[k++] = num[p1++];
        } else {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * r - l + 1);
    free(temp);
    return;
}

void raddix_sort(int *nums, int n) {
    #define MAX_N 65536
    int *temp = (int *)malloc(sizeof(int) * n);
    int cnt[MAX_N] = {0};
    for (int i = 0; i < n; ++i) {
        cnt[lowbit(nums[i])]++;
    }
    for (int i = 0; i < MAX_N; ++i) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        temp[--cnt[lowbit(nums[i])]] = nums[i];
    }

    for (int i = 0; i < n; ++i) {
        cnt[highbit(temp[i])]++;
    }
    for (int i = 0; i < MAX_N; ++i) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        nums[--cnt[highbit(temp[i])]] = temp[i];
    }
    #undef MAX_N
}
