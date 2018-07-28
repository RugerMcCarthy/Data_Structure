/*************************************************************************
	> File Name: gcd.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  5/29 09:16:12 2018
 ************************************************************************/

#include <stdio.h>
int gcd(int a, int b) {
    while (b^=a^=b^=a%=b);
    return a;
}
int main() {

    printf("%d\n", gcd(1452, 654));
}
