#include<stdio.h>
#include<string.h>
int searchs1(char a[], char s[],int lena, int lens){
    int ok;
    for(int i = 0; i <= lens - lena; ++i){
        for(int j = i; j < i + lena; ++j){
            ok = 1;
            if(s[j] != a[(j - i)%lena]){
                ok = 0;
                break;
            }
        }
        if(ok){
            return i + lena - 1;
        }
    }
    if(!ok) return -1;
}

int searchs2(char a[], char s[],int lena, int lens){
    int ok;
    for(int i = lens - 1; i >= lena - 1; --i){
        ok = 1;
        for(int j = i; j > i - lena; --j){
            if(s[j] != a[lena - 1 - (i - j)%lena]){
                ok = 0;
                break;
            }
        }
        if(ok){
            return i - lena;
        }
    }
    if(!ok) return -1;
}
int main(){
    char s[1000] = {}, s1[1000] = {}, s2[1000] = {};
    scanf("%s%s%s", s, s1, s2);
    int count1 = searchs1(s1, s, strlen(s1), strlen(s));
    int count2 = searchs2(s2, s, strlen(s2), strlen(s));
    if(count1 != -1 && count2 != -1 && count2 - count1 > 0)
        printf("%d", count2 - count1);
    else printf("-1");
return 0;
}