#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
int n = 0;
int flag[100] = {};
int sig(int left, int right){
    if(left == 0 && right == 0) return 1; 
    else if(left < 0 || right < 0) return 0;
    return sig(left - 1, right + 1) + sig(left, right - 1);
}
void sig1(int left, int right, int total){
    if(left == 0 && right == 0){
        for(int i = 0; i < 2*n; ++i){
            if(flag[i]) putchar('(');
            else putchar(')');
        }
        putchar('\n');
    }
    else if(left < 0 || right < 0) return;
    if(left > 0){
        flag[total] = 1;
        sig1(left - 1, right + 1, total+1);
        flag[total] = 0;
    }
    if(right > 0){
        flag[total] = 0;
        sig1(left, right - 1, total+1);
    }
}
int main(){
    scanf("%d", &n);
    printf("%d\n", sig(n, 0));
    sig1(n, 0, 0);
return 0;
}