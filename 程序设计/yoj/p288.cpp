#include<stdio.h>
#include<iostream>
int main(){
    char s1[200] = {}, s2[200] = {};
    char m, n;
    int i1 = 0, i2 = 0;
    std::cin.getline(s1, 200);
    std::cin.getline(s2, 200);
    while(1){
        for(i1; s1[i1] != 0;){
            if(s1[i1] != ' ') m = s1[i1];
            i1++;
            break;
        }
        for(i2; s1[i2] != 0;){
            if(s2[i2] != ' ') n = s2[i2];
            i2++;
            break;
            }
            int n1 = m - n;
            if(n1 != 0){
                printf("%d", n1);
                break;
            }
    }
return 0;
}