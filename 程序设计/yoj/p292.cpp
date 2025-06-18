#include<stdio.h>
#include<cmath>
double f(double x){
    if(x <= 1 and x >= -1) return -x-1;
    else return 1/(1+x*x);
}
int main(){
    double a = 0;
    scanf("%lf", &a);
    double m = f(f(a));
    printf("%.2lf", m);
return 0;
}