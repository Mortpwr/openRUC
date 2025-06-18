#include<stdio.h>
#include<string.h>
#include <iostream>// if a or b has blank? how to improve?
int main(){
    char s[500] = {};
    char a[200] = {}, b[200] = {};
    char ins = 0;
    std::cin.getline(s, 300);
    scanf("\n%c",&ins);
    int lens = strlen(s);
    if(ins == 'C'){
            scanf("%s", a);
            int count = 0;
            int lena = strlen(a);
            for(int i = 0; i <= lens - lena; ++i){
                int ok = 1;
                for(int j = 0; j < lena; ++j){
                    if(s[i + j] != a[j]) ok = 0;
                }
                if(ok){
                    count++;
                    i += lena - 1;
                }
            }
            printf("%d", count);
    }
    else if(ins == 'D'){
            scanf("%s", a);
            int lena1 = strlen(a);
            for(int i = 0; i <= lens - lena1; ++i){
                int ok = 1;
                for(int j = 0; j < lena1; ++j){
                    if(s[i + j] != a[j]) ok = 0;
                }
                if(!ok) printf("%c", s[i]);
                else{
                    for(int k = i + lena1; k < lens; ++k) printf("%c", s[k]);
                    break;
                }
            }
    }
    else if(ins == 'I'){
            scanf("%s %s", a, b);
            int lena2 = strlen(a);
            int index = 0;
            for(int i = 0; i <= lens - lena2; ++i){
                int ok = 1;
                for(int j = 0; j < lena2; ++j){
                    if(s[i + j] != a[j]) ok = 0;
                }
                if(ok) index = i;
            }
            for(int k = 0; k < lens;++k){
                if(k == index && index != 0) printf("%s%c", b, s[k]); // the index cant be 0!
                else printf("%c", s[k]);
            }
    }
    else if(ins == 'R'){
            scanf("%s %s", a, b);
            int lena3 = strlen(a);
            for(int i = 0; i <= lens - lena3; ++i){
                int ok = 1;
                for(int j = 0; j < lena3; ++j){
                    if(s[i + j] != a[j]) ok = 0;
                }
                if(ok){
                    printf("%s", b);
                    i = i + lena3 - 1;
                }
                else printf("%c", s[i]);
            }
    }
return 0;
}