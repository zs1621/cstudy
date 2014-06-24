#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void main () {
    char a[6][6];
    char kill[6][5];
    int b[6];
    int c[6];
    int i,j, k;
    for ( i = 0; i < 6; i++ ) {
        scanf("%6s %3d", a[i], &b[i]);
    }
    for ( i = 0; i < 6; i++ ) {
        k = 5;
        for (j = 0; j < 6; j++) {
            k -= 1;
            if ( a[i][j] == '.' ) {
                c[i] = j;
                k = k + 1;
            } else {
                kill[i][k] = a[i][j]; 
            }
        } 
    }
    for ( i = 0; i < 6; i++) {
        int s[5];
        for ( j = 0; j < 5; j++) {
            printf("%c--", kill[i][j]);
        }
    }
}

int result[6][125];

/************************
 *                      *
 *  @param s 求方的值   *
 *  @param res 结果     *
 *  @param num 求方次数 *
 *                      *
 ************************/
void mul(int *s, int *res, int num) {
    //TODO

}



