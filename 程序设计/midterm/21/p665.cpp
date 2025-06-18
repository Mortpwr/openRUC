#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
int main(){
    int a[10000] = {};
    for(int i = 2; i < 10000; ++i){
        int ok = 1;
        for(int j = 2; j <= sqrt(i); ++j){
            if(i % j == 0) ok = 0;
        }
        if(ok) a[i] = 1;
    }
    int n = 0;
    scanf("%d", &n);
    int ok = 0, x = 0, p = 0, q = 0;
    for(int i = n+1; ok != 1; ++i){
        ok = 0, p = 0, q = 0;
        x = i;
        for(int j = 2; j < 10000; ++j){
            if(a[j] == 1 && i % j == 0){
                p = j;
                q = i/j;
                if(a[q] == 1){
                    ok = 1;
                    break;
                }
            }
        }
    }
    int num = 0;
    int mi = floor(sqrt(x));
    if(mi*mi == x) num = 1;
    if(num == 0){
        for(int i = 1; i <= mi; ++i){
            for(int j = 1; j <= mi; ++j){
                if(i*i + j*j == x) num = 2;
            }
        }
    }
    if(num == 0){
        for(int i = 1; i <= mi; ++i){
            for(int j = 1; j <= mi; ++j){
                for(int k = 1; k <= mi; ++k){
                    if(i*i + j*j + k*k == x) num = 3;
                }
            }
        }
    }
    if(num == 0) num = 4;
    printf("%d %d\n%d", p, q, num);
return 0;
}