#include<stdio.h>
#include<math.h>
int main(){
    double a;
    scanf("%lf", &a);
    if(a < 0) printf("%.2lf", -a);
    else if(a >= 0 && a <= 1) printf("%.2lf", sqrt(a));
    else printf("%.2lf", a*a); 
return 0;
}