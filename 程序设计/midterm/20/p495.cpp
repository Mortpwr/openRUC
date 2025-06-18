#include<stdio.h>
int main(){
    double a, b, c, n;
    scanf("%lf%lf%lf%lf", &n, &a, &b, &c);
    double num = n, count = 0;
    while(num-300 >= 0){
         count++;
         num = num-300;
    }
    n = n - count*40;
    if(n >= a) n = n-b;
    n = n-c;
    if(n < 0) printf("0.00");
    else printf("%.2lf", n);
return 0;
}