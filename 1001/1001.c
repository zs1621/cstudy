#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void main () {
    float a[6];
    int b[6];
    char c[100];
    int i;
    for ( i = 0; i < 6; i++ ) {
        scanf("%f", &a[i]);
        scanf("%d", &b[i]);
    }
    for ( i = 0; i < 6; i++ ) {
        snprintf(c, "%f", pow(a[i], b[i]);
    }
    printf("%s", c);
}

