#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int i,j,k;
char a1[50], a2[50];
int s1[50], s2[50];
int lena1;
int lena2;
int s[100];

void mul(int *s1, int *s2, int *s)
{
    for (i=0; i < strlen(a1); i++) {
        for (j=0; j < strlen(a2); j++) {
            s[i+j] += s1[i] * s2[j];
        }
    }
    int k = strlen(a1) + strlen(a2); 
    while (!s[k]) 
        --k;
    for(i=0,j=0; i <= k; i++)
    {
        s[i+1] += s[i] / 10;
        s[i] %= 10;
    }
}

int main ()
{
    gets(a1);
    gets(a2);
    lena1 = strlen(a1);
    lena2 = strlen(a2);
    int m = lena1 + lena2;
    for (i=lena1  - 1; i >= 0; --i) {
        s1[i] = (a1[lena1 - i - 1] - '0');
    }
    for (i=lena2  - 1; i >= 0; --i) 
        s2[i] = (a2[lena2 - i - 1] - '0');
    for (i=0; i < 100; i++)
        s[i] = 0;
    mul(s1, s2, s);
    
    while (!s[m])
        --m;
    for (i= m ; i >=0; --i)  {
        printf("%d:", i);
        printf("%d ~~~\n", s[i]);
    }
    return 9;
}
