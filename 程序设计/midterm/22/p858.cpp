#include<stdio.h>
#include<string.h>
#include<math.h>
struct num{
    char s[100] = {};
    long long snum = 0;
    int iteral = 0;
    long long final = 0;
};
long long turn(long long a){
    long long m = 0;
    while(a > 0){
        m = m*10 + a%10;
        a = a/10;
    }
    return m;
}
int judge(char a[], int len){
    int ok = 0;
    for(int i = 0; i < len; ++i)
        if(a[i] != a [len - i - 1]) ok = 1;
    return ok;
}
void insertion_sort(num *a, int n){
    num key;
    for(int i = 1; i < n; ++i){
        key = a[i];
        int j = i - 1;
        for(; j >= 0 && a[j].snum > key.snum; --j) a[j + 1] = a[j];
        a[j + 1] = key;
    }
}
void insertion_sort1(num *a, int n){
    num key;
    for(int i = 1; i < n; ++i){
        key = a[i];
        int j = i - 1;
        for(; j >= 0 && a[j].final > key.final; --j) a[j + 1] = a[j];
        a[j + 1] = key;
    }
}
void insertion_sort2(num *a, int n){
    num key;
    for(int i = 1; i < n; ++i){
        key = a[i];
        int j = i - 1;
        for(; j >= 0 && a[j].iteral < key.iteral; --j) a[j + 1] = a[j];
        a[j + 1] = key;
    }
}
int main(){
    num n[10];
    for(int i = 0; i < 10 ; ++i) {
        scanf("%lld", &n[i].final);
        n[i].snum = n[i].final;
        sprintf(n[i].s, "%lld", n[i].final);
        }
    for(int i = 0; i < 10; ++i){
        int len = strlen(n[i].s); 
        while(judge(n[i].s, len)){
            n[i].iteral++;
            n[i].final = n[i].final + turn(n[i].final);
            sprintf(n[i].s, "%lld", n[i].final);
            len = strlen(n[i].s);
        }
    }
    insertion_sort(n, 10);
    insertion_sort1(n, 10);
    insertion_sort2(n, 10);
    for(int i = 0; i < 10; ++i){
        printf("%lld %lld %lld\n", n[i].snum, n[i].iteral, n[i].final); // lld!
    }
return 0;
}