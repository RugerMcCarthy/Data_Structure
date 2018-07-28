#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define SWAP(a, b) {\
    __typeof(a) temp = a;\
    a = b;\
    b = temp;\
}
void output(int *num, int n) {
    printf("[");
    for (int i = 0; i < n; ++i) {
        printf("%d ", num[i]);
    }
    printf("]\n");
}
int select_sort(int*, int);
void quick_sort(int*, int, int);
void ungarded_insert_sort(int*, int);

int main() {
    srand(time(0));
    int num[30] = {0};
    printf("[");
    for (int i = 0; i < 30; ++i) {
        num[i] = rand() % 100;
        printf("%d ", num[i]);
    }
    printf("]\n");
    quick_sort(num, 0, 29);
    output(num, 30);
    return 0;
}
int select_sort(int* nums, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int pos = i, min_value = 0x7fffffff;
        for (int j = i + 1; j < n; ++j) {
            if (min_value > nums[j]) {
                min_value = nums[j];
                pos = j;
            }
        }
        SWAP(nums[pos], nums[i]);
    }
}
void quick_sort(int *nums, int l, int r) {
        int p = l, q = r;
        while (r - l >= 16) {
            int pivot = nums[rand() % (r - l + 1) + l]; // 搅乱原数组 打消最坏情况
            int p = l, q = r;
            do {
                while (nums[p] < pivot) ++p;
                while (nums[q] > pivot) --q;
                if (p < q) {
                    SWAP(nums[p], nums[q]);
                    ++p, --q;
                }
            } while (p <= q);
            quick_sort(nums, l, q);
            l = p;
        }
        ungarded_insert_sort(nums + l, r - l + 1);
}
void ungarded_insert_sort(int* nums , int n) {
    int ind = 0;
    for (int i = 1; i < n; ++i) {
        if (nums[i] < nums[ind]) ind = i;
    }
    SWAP(nums[ind], nums[0]);
    for (int i = 2; i < n; ++i) {
        int j = i;
        while (nums[j] < nums[j - 1]) {  //STL  非监督(减少n^2的边界条件判断)
            SWAP(nums[j], nums[j - 1]);
            j--;
        }
    }
    return;
}
