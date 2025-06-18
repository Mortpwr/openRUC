#include<stdio.h>
#include<string.h>
struct se{
    int index = 0;
};
int a[100000] = {};
int main(){
    int m, n;
    se seq[100];
    scanf("%d", &m);
    for(int i = 0; i < m; ++i){
        scanf("%d", &n);
        memset(a, 0 , sizeof(a));
        for(int j = 0; j < n; ++j){
            scanf("%d", &a[j]);
        }
        for(int j = 0; j < n; ++j){
            seq[i].index = j;
            if(a[j] >= a[j+1]) break;
        }
        if(seq[i].index == n - 1) printf("YES");
        else{
            for(int j = 0; j < seq[i].index + 1; ++j){
                printf("%d ", a[j]);
            }
        }
        putchar('\n');
    }
return 0;
}