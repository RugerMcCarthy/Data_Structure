/************************************************************************
	> File Name: zeller.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  5/12 10:44:33 2018
************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>
int main(){
    int y, m, d;
    int dnum[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
    while (~scanf("%d %d %d", &y, &m, &d)) {
        int w = ((d-1) + y + (y / 4) - (y / 100) + (y / 400) + dnum[m - 1]) % 7;
        if (m < 3 && (y % 4==0 && y%100!=0 || y%400==0) && y != 0){
            w--;
        }
        printf ("%d\n", w);
    }return 0;
}
