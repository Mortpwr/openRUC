#include<stdio.h>
#include<algorithm>
#include <string.h>
int main(){
    int N = 0, i = 0;
    int a[5] = {}, count = 0;
    scanf("%d", &N); 
    char interval[50][4] = {};
    while(scanf("%s", interval[i]) && interval[i][0] != '0') i++;
    for(int j = 0; j < i; ++j){
        if(!strcmp(interval[j], "1AB")) a[0]++;
        else if(!strcmp(interval[j], "2AB")) a[0]--;
        if(!strcmp(interval[j], "1AC")) a[1]++;
        else if(!strcmp(interval[j], "2AC")) a[1]--;
        if(!strcmp(interval[j], "1AD")) count++;
        else if(!strcmp(interval[j], "2AD")) count--;
        if(!strcmp(interval[j], "1BC")) a[2]++;
        else if(!strcmp(interval[j], "2BC")) a[2]--;
        if(!strcmp(interval[j], "1BD")) a[3]++;
        else if(!strcmp(interval[j], "2BD")) a[3]--;
        if(!strcmp(interval[j], "1CD")) a[4]++;
        else if(!strcmp(interval[j], "2CD")) a[4]--;
    }
    while(a[0] && a[2] && a[4]){
        count++;
        a[0]--;
        a[2]--;
        a[4]--;
    }
    for(int m = 2; m < 5; ++m)
        while(a[0] && a[m]){
            count++;
            a[0]--;
            a[m]--;
        }
    while(a[1] && a[4]){
            count++;
            a[1]--;
            a[4]--;
        }
    
    while(a[2] && a[4]){
        count++;
        a[2]--;
        a[4]--;
    }
    for(int m = 0; m < 5; ++m) count += a[m];
    printf("%d", N - count);        
return 0;
} 