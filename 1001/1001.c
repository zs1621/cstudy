#include <math.h>
#include <stdlib.h>
int mnum = 0;
int lena = 1;
int lenb = 1;
int len = 2;
int x,y,z;
int i,j,k;
int result[6][125];
/************************
 *                      *
 *  @param s1 乘数   *
 *  @param s2 乘数    *
 *  @param s 结果 *
 *                      *
 ************************/

 
void muls(int *s1, int *s2, int *s)
{
    for (i=0; i < lena; i++) {
        for (j=0; j < lenb; j++) {
            s[i+j] += s1[i] * s2[j];
        }
    }
    int k = len; 
    while (!s[k]) 
        --k;
    for(i=0,j=0; i <= k; i++)
    {
        s[i+1] += s[i] / 10;
        s[i] %= 10;
    }
}
   
/************************
 *                      *
 *  @param s 求方的值   *
 *  @param res 结果     *
 *  @param num 求方次数 *
 *                      *
 ************************/
void mul(int *s, int *res, int num) {
    for (mnum = 0; mnum < num; mnum++) {
        if (mnum == 0) {
            muls(s, s, res);   
            while (!res[len]) {
                --len; 
            }
            lena = len;
            lenb = 5;
            len = lena + lenb;
        } else {
            muls(res, s, res);
            while (!res[len]) {
                --len; 
            }
            lena = len;
            lenb = 5;
            len = lena + lenb;
        }
    }
}


void main () {
    char a[6][6];
    char kill[6][5];
    int live[6][5];
    int b[6];
    int c[6];
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
        for ( j = 0; j < 5; j++) {
            //printf("%c--", kill[i][j]);
        }
    }

    for ( x= 0; x < 6; x++) {
        for (i = 0; i < 5; i++) {
            live[x][i] = (kill[x][i] - '0');
      //    printf("%d ppp %d zz", live[x][i], i);
        } 
    }
    for ( x=0; x < 6; x++ ) {
        int s[5] = {0};
        int res[125] = {0};
        for (y = 0; y < 5; y++) {
            s[y] = live[x][y];
            printf("%d\n", s[y]);
        } 
        printf("--%d--", b[x]);
        printf("------------------------------------------");
        mul(s, res, b[x]);
        for ( y = 0; y < 125; y++) {
            if (y == 124) {
                printf("\n");
            } else {
                printf("%d", res[y]); 
            }
        }
    }
}

