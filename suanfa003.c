#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
int *out;  
int out_size;  
void bag(int n, int m)  
{  
        int i;  
        if (n < 1 || m < 1 || (n == 1 && m != 1))  
                return;  
        if (m == n) {  
                out[n] = 1;  
                for (i = 1; i <= out_size; i++) {  
                        if (out[i])  
                                printf("%d ", i);  
                }  
                printf("\n");  
                out[n] = 0;  
        }  
        bag(n - 1, m);  
        out[n] = 1;  
        bag(n - 1, m - n);  
        out[n] = 0;  
  
}  
  
int main()  
{  
        int n, m;  
        printf("Please input two num(n,m):");  
        scanf("%d%d", &n, &m);  
        if (n > m)  
                n = m;  
        out_size = n;  
        out = (int *)malloc((n + 1) * sizeof(int));  
        memset(out, 0, (n + 1) * sizeof(int));  
        bag(n, m);  
        free(out);  
        return 0;  
;
        
