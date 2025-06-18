#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
void copy(int a[], int b[], int len){
    for(int i = 0; i < len; ++i){
        b[i] = a[i];
    }
}
int chsort(int a[], int len, int now){
    int b[100];
    if(now == len - 1) return 0;
    int swap = 0, min = a[now], index = 0, m = 0, ok = 0;
    for(int i = now + 1; i < len; ++i){
        if(min > a[i]){ 
            min = a[i];
            index = i;
            ok = 1;
        }
    }
     if(ok){
        swap = a[now];
        a[now] = a[index];
        a[index] = swap;
        copy(a, b, len);
        m = 1+chsort(a, len, now+1);
        printf("%d<->%d:", now+1, index+1);
        for(int i = 0; i < len; ++i){
            printf("%d ", b[i]);
        }
        putchar('\n');
        }
    else m = chsort(a, len, now+1);
    return m;
}
int main(){ 
    int n, a[200] = {};
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    int m = chsort(a, n, 0);
    printf("Total steps:%d\n", m);
    printf("Right order:");
    for(int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
return 0;
}