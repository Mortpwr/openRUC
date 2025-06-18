#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
int main(){
    int a[100][100] = {};
    int n;
    int min = 0x7fffffff;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < n; ++i){
        if(min > a[i][i]) min = a[i][i];
    }
    for(int i = 0; i < n; ++i){
        if(min > a[i][n-i-1]) min = a[i][n-i-1];
    }
    printf("%d", min);
return 0;
}