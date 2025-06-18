#include <stdio.h>
#include <stdlib.h>


int findMax( int *p, int nSize )
{
    int max = -0x7fffffff, index = 0;
    for(int i = 0; i < nSize; ++i){
        if(*(p+i) > max){
            max = *(p+i);
            index = i;
        }
    }
    *(p+index) = *p;
    *p = max;
    return max;
}


int main()
{
    int ary[2100]={3, 2, 1, 5, 6, 7, 9, 10}, n = 8, nMax, i;
    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
        scanf("%d", &ary[i]);

    nMax = findMax(ary, n);
    
    for ( i = 0; i < n; i++ )
        printf( "%d ", ary[i] );
    printf("\n");

    printf("%d\n", nMax);
    return 0;
}