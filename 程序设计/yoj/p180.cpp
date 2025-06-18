#include<stdio.h>
#include<cmath>
double fact(double a){
    if(a == 0) return 1;
    return a*fact(a-1);
}
double dabs(double n){
    if(n < 0) return -n;
    else return n;
}
int main(){
    double x, error, aprosin = 0, aprocos = 0;
    scanf("%lf%lf", &x, &error);
    int i = 1, j = 0;
    while(dabs(x) > 2*(M_PI)){
        x -= 2*(M_PI);
    }
    double SIN = sin(x), COS = cos(x);
    while(dabs(aprosin - SIN) >= error){
        aprosin += (pow(x, 2*i-1))*(pow(-1, i-1))/(fact(2*i-1)*1.0);
        i = i+1;
    }
    while(dabs(aprocos - COS) >= error){
        aprocos += (pow(x, 2*j))*(pow(-1, j))/(fact(2*j)*1.0);
        j = j+1;
    }
    printf("%lf\n%lf", aprosin, aprocos);
return 0;
}//i 和 j复制粘贴时候一定要看清！！！