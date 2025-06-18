#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
int array[26] = {};
bool prime(int n){
    int ok = 1;
    for(int i = 3; i <= sqrt(n); ++i){
        if(n % i == 0) ok = 0;
    }
    if(n == 2) return true;
    else if(n <= 2) return false;
    else if(ok) return true;
    else return false;
}
int main(){
    char s[105] = {};
    scanf("%s", s);
    for(int i = 0; i < strlen(s); ++i){
        array[s[i]-'a']++;
    }
    int maxn = -0x7fffffff, minn = +0x7ffffff;
    for(int i = 0; i < 26; ++i){
        if(array[i] == 0);
        else{   
            if(maxn < array[i]) maxn = array[i];
            if(minn > array[i]) minn = array[i];
        }
    }
    bool ok = prime(maxn - minn);
    if(ok){
            printf("Lucky Word");
            printf("\n%d", maxn - minn);
    }
    else{
        printf("No Answer\n0");
    }
return 0;
}