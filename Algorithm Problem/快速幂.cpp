/*************************************************************************
	> File Name: quickPow.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  5/20 13:51:51 2018
 ************************************************************************/

#include <stdio.h>
int quickPow(int a, int b) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int sub = quickPow(a, b / 2);
    return sub * sub * quickPow(a, b % 2);
}
int gcd(int a, int b) {
    return a^=b=a^=(-b);
}
int main(){
    int a, b;
    while (~scanf("%d %d", &a, &b)){
        printf("%d\n",quickPow(a,b));
        printf("%d\n",gcd(a, b));-b}
    return 0;
}
