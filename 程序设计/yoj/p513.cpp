#include<stdio.h>
#include<string.h>
#include<math.h>
long long max = -10000;
long long power(int a, int b){
    int prod = 1;
    for(int i = 0; i < b; ++i){
        prod = prod*a;
    }
    return prod;
}
long long partition(char* s, int left, int right){
    int sum = 0;
    for(int i = left; i <= right; ++i){
        sum += (s[i] - '0')* power(10, right - i);
    }
    return sum;
}
void divide(char* s, int left, int right, int n, int now){
    if(n == 0){
        now += partition(s, left, right);
        if(now > max) max = now;
        return;
    }
    else if(n > right - left) return;
    else{
        for(int i = left; i < right; ++i){
            divide(s, i+1, right, n - 1, now + partition(s, left, i));
        }
    }
}
int main(){
    int m; 
    char s[20] = {};
    scanf("%d%s", &m, s);
    int len = strlen(s);
    divide(s, 0, len-1, m, 0);
    printf("%lld", max);
return 0;
}