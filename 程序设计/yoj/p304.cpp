#include<stdio.h>
#include<cmath>
int digit(int n){
    int count = 0;
    while(n != 0){
        n = n/10;
        count++;
    }
    return count;
}
int main(){
    int a, b, n, k, m;
    int count = 0;
    scanf("%d%d%d%d%d", &a, &b, &n, &k, &m);
    int digita = digit(a), digitb = digit(b);
    if(digita > m or digitb < m) b = -1;
    else if(digita < m) a = pow(10, m-1);
    if(digitb > m) b = pow(10, m)-1;
    for(int i = a; i <= b; ++i){
        if(i%10 == n && i%k == 0) count++;
    }     
    printf("%d", count);
return 0;
}