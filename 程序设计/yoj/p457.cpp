#include<stdio.h>
int main(){
    int n;
    char A = 'A';
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        for(int s = 1; s <= n-i; s++){
            putchar(' ');
        }
        for(int j = 0; j <= (2*i-1)/2; ++j){
            printf("%c", A+j);
            if(j == (2*i-1)/2+1) break;
        }
        for(int j = (2*i-1)/2-1; j >= 0; --j){
            printf("%c", A+j);
        }
        for(int s = 1; s <= n-i; s++){
            putchar(' ');
        }
        putchar('\n');
    }    
return 0;
}