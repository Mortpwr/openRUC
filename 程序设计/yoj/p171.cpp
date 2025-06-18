#include<stdio.h>
int main(){
    long long a, b;
    char s;
    scanf("%lld %lld %c", &a, &b, &s);
    if(b == 0){
        printf("NO");
        return 0;
    }
    switch(s){
        case '+' : 
            long long x;
            x = a + b;
            printf("%lld\n", x);
            break;  
        case '-': 
            printf("%lld", a-b);
            break;  
        case '*': 
            printf("%lld", a*b);
            break;  
        case '/' : 
            printf("%lld", a/b);
            break;  
        case '%': 
            printf("%lld", a%b); 
            break;  
        default:
            break;   
    }  
return 0;
}