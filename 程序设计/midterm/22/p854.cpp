#include<stdio.h>
int num[1000001] = {};
int negnum[1000001] = {};
int main(){
    int n; 
    long long sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int m = 0, k = 0;
        scanf("%d", &m);
        for(int j = 0; j < m; ++j){
            k = 0;
            scanf("%d", &k);
            if(k >= 0) num[k]++;
            else negnum[-k]++;
        }
    }
    for(int i = 0; i < 1000001; ++i){
        if(num[i] == 1) sum += i;
        if(negnum[i] == 1) sum -=i;
    }
    printf("%lld", sum);
return 0;
}