#include<stdio.h>
int main(){
    int k, count = 0;
    double sum = 0;
    scanf("%d", &k);
    for(double i = 1; sum <= k; ++i){
        sum += 1/i;
        count++;
    }      
    printf("%d", count);
return 0;
}