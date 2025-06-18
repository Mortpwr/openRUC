#include<stdio.h>
int main(){
    int a [10000] = {};
    int n = 0;
    scanf("%d", &n);
    for(int i = 2; i <= n; ++i){
        if(n % i == 0){ 
            a[i]++;
            n = n/i;
            i = 1;
            continue;
        }
    }
    for(int i = 0; i < 10000; ++i){
        if(a[i] != 0) printf("%d:%d\n", i, a[i]);
    }
return 0;
}