#include <stdio.h>
#include <stdlib.h>


/************************
高精度加法
*************************/


//void main () {
//    int a[2] = {9, 9};
//    int b[2] = {9, 9};
//    int c[4] = {0};
//    int i, j;
//    for (i=0; i < 2; i++) { 
//        for(j=0; j < 2; j++) {
//   	    c[i+j] += a[i] * b[j];
//	}
//    }
//    for (i=0; i < 4; i++ ) {
//	c [i+1] += c[i] / 10;
//	c [i] = c[i] % 10;
//	printf("%d", c[i]);
//    }
//    
//}

int * multi (int a[], int b[]) {
    int lena = 0;
    int lenb = 0;
    while (a[lena]) lena++;
    while (b[lenb]) lenb++;
    int total = lena + lenb;
    int *c = (int*)malloc(sizeof(int)*total);
    int *d = (int*)malloc(sizeof(int)*total);
    int c_num = 0;
    for (; c_num < total; c_num++) {
        *(c+c_num) = 0;
    }
    int i, j;
    for (i = 0; i < lena; i++) {
	for (j = 0; j < lenb; j++) {
            c[i+j] += a[i] * b[j]; 
        }
    }
    for (i = 0; i < total - 1; i++) {
	c[i+1] += c[i] / 10;
        c[i] = c[i] % 10;
    }
    int mid_num;
    if (c[total - 1] == 0 && c[total-2] == 0) {
	d[0] = 0;
        free(c);
        return d;
    }
    if (c[total - 1] == 0) {
	for (i = total - 2,j = 0; i >= 0; i--, j++) {
            d[j] = c[i];
        }
    } else {
	for (i = total - 1,j = 0; i >= 0; i--, j++) {
            d[j] = c[i];
        }
    }
    free(c);
    return d;
}

void main () {
   int a[] = {9,9,NULL};
   int b[] = {0,NULL};
   int len_a = 0;
   int len_b = 0;
   while (a[len_a]) len_a++;
   while (b[len_b]) len_b++;
   int *c;
   c = multi(a, b);
   int j;
   for (j = 0; j < len_a + len_b ; j++) {
       if (c[j] > 9) break;
       printf("%d -- ", c[j]);
   }
   free(c);
}
