#include<stdio.h>
int main(){
    int n, x;
    scanf("%d", &n);
    int value[n];
    for(int i = 0; i < n; ++i){
        scanf("%d", &value[i]);
    }
    scanf("%d", &x);
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j){
            if(value[i] + value[j] == x) printf("%d %d", i+1, j+1);
        }
return 0;
}