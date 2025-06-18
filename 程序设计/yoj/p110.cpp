#include<stdio.h>
#include<string.h>
int main(){
    char s[1005];
    scanf("%s", s);
    int ok_p = 1;
    for(int i = 0; i <= (strlen(s)/2); ++i){  
        if(s[i] != s[strlen(s)-1-i]){
            ok_p = 0;
            break;
        }
    }
    if(ok_p) printf("Yes");
    else printf("No");  
return 0;
}