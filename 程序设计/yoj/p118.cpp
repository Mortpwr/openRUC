#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
int mat[2][2] = {1, 1, 1, 0};
int now[2][2] = {1, 0, 0, 1};
int ten_base[2][2] = {1, 1, 1, 0};
int ten_base1[2][2] = {1, 1, 1, 0};
int a[100] = {};
int I[2][2] = {1, 0, 0, 91};
void divide(int n){
    for(int i = 0; n > 0; ++i){
        a[i] = n % 10;
        n = n/10;
    }
}
void mod_mul(int (*a)[2], int (*b)[2], int (*c)[2]){
    int final[2][2] = {};
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k < 2; ++k){
                final[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            if(final[i][j] >= 10000) final[i][j] = final[i][j]%10000;
            c[i][j] = final[i][j];
        }
    }
}
int main(){
    int n = 0;
    scanf("%d", &n);
    if(n == 0){
        printf("0");
        return 0;
    }
    memset(a, -1, sizeof(a));
    divide(n);
    for(int i = 0; a[i] != -1; ++i){
        for(int j = 0; j < a[i]; ++j){
            mod_mul(ten_base, now, now);
        }
        for(int j = 1; j < 10; ++j){
            mod_mul(ten_base, ten_base1, ten_base1);
        }
        mod_mul(ten_base1, I, ten_base);
    }
    printf("%d", now[0][1]);
return 0;
}