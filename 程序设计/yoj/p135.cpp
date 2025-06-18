#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<iostream>
struct number{
    char s[19] = {};
    int num = 0;
};
void insort(number a[], int len){
    for(int i = 1; i < len; ++i){
        int j = i - 1;
        number key = a[i];
        while(j >= 0 && a[j].num < key.num){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main(){
    int n;
    number id[100000];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%s", id[i].s);
        for(int j = 6; j < 14; ++j){
            id[i].num = id[i].num*10 + id[i].s[j] - '0';
        }
    }
    std::sort(id, id+n, [](number a, number b){if(a.num != b.num) return a.num > b.num; if(strcmp(a.s, b.s) > 0) return true; else return false;});
    for(int i = 0; i < n; ++i){
        printf("%s\n", id[i].s);
    }
return 0;
}