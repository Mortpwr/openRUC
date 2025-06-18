#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
int judge[100000] = {};
int main(){
    int n, d, l, r, ok = 0;
    scanf("%d%d",&n, &d);
    int a[100000] = {};
    for(int i = 0; i < 100000; ++i) a[i] = -2;
    a[0] = n/d;
    a[1] = -1;
    n = n%d;
    for(int k = 2; k < 100000; ++k){
        n = n*10;
        judge[k] = n%d;
        a[k] = n / d;
        n = n%d;
        if(n == 0){
            r = k+1;
            break;
        }
        for(int m = k; m >= 2; --m){
            if(judge[m] == judge[k] && m != k && a[m] == a[k]){
                l = m;
                r = k;
                ok = 1;
                break;
            }
        }
        if(ok) break;
    }
    for(int i = 0; i < r; ++i){
        if(n == 0){
            if(a[i] == -1) printf(".");
            else printf("%d", a[i]);
        }
        else{
            if(a[i] == -1) printf(".");
            else{ 
                if(i == l && l == r - 1) printf("(%d)", a[i]);
                else{
                    if(i == l) printf("(%d", a[i]);
                    else if(i == r-1) printf("%d)", a[i]);
                    else printf("%d", a[i]);
                }
            } 
        }
    }
return 0;
}
