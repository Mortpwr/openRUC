#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
void statis(int left, int right, char* s, int* a){
    for(int i = left; i < right; ++i){
        a[s[i] - 'a']++;
    }
}
int cmp(int *a, int *b){
    for(int i = 0; i < 26; ++i){
        if(a[i] != b[i]) return 0;
    }
    return 1;
}
int main(){
    int ok = 1; 
    char s[500] = {};
    char s1[500] = {};
    int sta[26] = {};
    int sta1[26] = {};
    scanf("%s%s",s, s1);
    int len1 = strlen(s);
    int len2 = strlen(s1);
    if(len2 < len1){
        printf("false");
        return 0;
    }
    statis(0, len1, s, sta);
    for(int i = 0; i <= len2 - len1; ++i){
        statis(i, i + len1, s1, sta1);
        ok = cmp(sta, sta1);
        if(ok){
            for(int j = i; j < i + len1; ++j){
                printf("%c", s1[j]);
            }
            return 0;
        }
        memset(sta1, 0, sizeof(sta1));
    }   
    if(!ok) printf("false");
return 0;
}