#include<stdio.h>
int main(){
    int n, m, ok1 = 1, ok2 = 1, ok3 = 1, ok4 = 1;
    int a[100][100];
    int b[100][100];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%d", &a[i][j]);
        }
    }      
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%d", &b[i][j]);
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(a[n-j-1][i] != b[i][j]) ok1 = 0;
            if(a[j][n-i-1] != b[i][j]) ok2 = 0;
            if(a[n-i-1][n-j-1] != b[i][j]) ok3 = 0;
            if(a[i][j] != b[i][j]) ok4 = 0;
        }
    }
    if(ok1) putchar('1');
    else if(ok2) putchar('2');
    else if(ok3) putchar('3');
    else if(ok4) putchar('4');
    else putchar('5');         
return 0;
}