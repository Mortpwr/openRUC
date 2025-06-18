#include<stdio.h>
#include<algorithm>
int judge(int a[]){
    int count1 = 0, count2 = 0, count4 = 0, ok = 1;
    std::sort(a, a+6);
    for(int i = 0; i < 6; ++i){
        if(i+1 != a[i]) ok = 0;
        if(a[i] == 1) count1++;
        if(a[i] == 2) count2++;
        if(a[i] == 4) count4++;
    }
    if(count4 == 4 && count1 == 2) return 2048;
    else if(count4 == 6) return 1024;
    else if(count1 == 6) return 512;
    else if(count2 == 6) return 256;
    else if(count4 == 5) return 128;
    else if(count2 == 5) return 64;
    else if(count4 == 4) return 32;
    else if(ok) return 16;
    else if(count4 == 3) return 8;
    else if(count2 == 4) return 4;
    else if(count4 == 2) return 2;
    else if(count4 == 1) return 1;
    else return 0;
}
int main(){
    int N =0, sum = 0;
    int s[6] = {};
    scanf("%d", &N);
    while(N-- && scanf("%d", s) != EOF){
        for(int i = 1; i < 6; ++i) scanf("%d", &s[i]);
        int now = judge(s);
        if(now == 0) break;
        else sum += now; 
    }
    printf("%x", sum);
return 0;
}