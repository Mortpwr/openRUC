#include<stdio.h>
int main(){
    char s[20];
    scanf("%s", s);
    int total = 0, code = 0, count = 0;
    for(int i = 0; count < 9; ++i){
        if(s[i] != '-'){
            total += (count+1)*(s[i] - '0');
            count += 1;
        }
    }
    code = total%11;
    if(code == 10 && s[12] == 'X') printf("Right");
    else if(code == (s[12] - '0')) printf("Right");
    else{
        if(code == 10){
            s[12] = 'X';
            printf("%s", s);
        }
        else{
            s[12] = '0' + code;
            printf("%s", s);
        }
    }
return 0;
}