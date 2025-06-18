#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#define ll long long
ll power(ll a, ll b){
    ll product = 1;
    for(int i = 0; i < b; ++i){
        product = product*a;
    }
    return product;
}
int main(){
    int l = -1, r = -1;
    ll sum = 0;
    char s[1005] = {};
    fgets(s, 1005, stdin);
    int lens = strlen(s);
    for(int i = 0; i < lens; ++i){
        if(s[i] >= '0' && s[i] <= '9' && l == -1){
            l = i;
            for(int j = i; j < lens; ++j){
                if(s[j] < '0' || s[j] > '9'){
                    r = j;
                    break;
                }  
            }
        if(l != -1 && r != -1) i = r-1;
        }
        for(int j = l; j < r; ++j){
            sum += (s[j] - '0')*power(10, r-j-1);
        }
        l = r = -1;
    }
    printf("%lld", sum);
return 0;
}