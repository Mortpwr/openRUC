#include<stdio.h>
void digits(int a[], int n){
    int i = 0;
    while(n > 0){
        a[i] = n%10;
        n = n/10;
        i++;
    }
}
int is_common(int a, int b){
    int s1[20];
    int s2[20];
    int ok = 1;
    for(int i = 0; i < 20; ++i){
        s1[i] = -1;
        s2[i] = -1;
    }
    digits(s1, a);
    digits(s2, b);
    for(int i = 0; s1[i] != -1; ++i) if(s1[i] != s2[i]) ok = 0;
    return ok;
}
int main(){
    int num[10001] = {};
    int a, b, sum = 0;
    scanf("%d%d", &a, &b);
    for(int i = 1; i < 10001; ++i)
        num[i] = is_common(i, i*i);
    for(int i = a; i <= b; ++i){
        if(num[i] == 1) sum += i;
    }
    printf("%d", sum);
return 0;
}