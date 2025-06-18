#include<stdio.h>
int main(){
    int n, count = 0;
    scanf("%d", &n);
    if (n == 0) printf("0,1");
    else {
        while(n > 0){
        count++;
        printf("%d,", n%10);
        n = n/10;
    }     
    printf("%d", count);
    }
return 0;
}