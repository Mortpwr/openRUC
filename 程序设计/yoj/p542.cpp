#include <stdio.h>
#include <stdlib.h>

void mySort(int* a, int left, int right)
{
 int i = left, j = right, base = a[left], t = 0;
    if(right > left){
        while(i < j){
            while(a[j] >= base && i < j) j--;
            while(a[i] <= base && i < j) i++;                                                                                                                                                        
            if(i < j){
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
        t = base;
        a[left] = a[i];
        a[i] = t;    
        mySort(a, left, i-1);
        mySort(a, i+1, right);
    }
    
}

int main()  
{  
    int array[100], i, n;
    
    scanf("%d",&n);

    for ( i = 0; i < n; i ++ ){
        scanf("%d", &array[i]);
    }

    mySort(array, 0, n-1);

    for ( i = 0; i < n; i ++ ){
        printf("%d ", array[i]);
    }
    printf("\n");  
    return 0;  
}  