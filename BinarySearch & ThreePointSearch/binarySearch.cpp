#include <stdio.h>
#include <math.h>
#define EPS 1e-6

int binary_search1(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] < x) {
            head = mid + 1;
        }else {
            tail = mid - 1;
        }
    }
    return -1;
}

int binary_search2(int *num, int n, int x) { //11110000 [last1]
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >>1; //È«ÊÇ1£¬ËÀÑ­»·
        if (num[mid] == 1) {
            head = mid;
        } else {
            tail = mid - 1;
        }
    }
    return head;
}

int binary_search3(int *num, int n, int x) { //00001111 [first1]
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1) {
            tail = mid;
        } else {
            head = mid + 1;
        }
    }
    return head == n ? -1:head;
}
int main() {
    return 0;
}
