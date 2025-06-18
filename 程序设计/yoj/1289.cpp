#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<ctype.h>
int main(){
    int countf = 0, countal = 0;
    char sig[] = {'!','&','|','>','.', '-'};
    int signal[128] = {0};
    int albe[128] = {0};
    char s[100] = {0};
    scanf("%s", s);
    for(int i = 0; i < strlen(s); ++i){
        if(isalpha(s[i])) albe[s[i]-'a']++;
        else signal[s[i]]++;
    }
    for(int i = 0; i < 26; ++i){
        if(albe[i] == 0) continue;
        else{ 
        printf("%d", albe[i]);
        putchar(i+'a');
        if(i != 25) putchar(' ');
        }
    }
    printf("\n");
        if(signal[33] != 0){ printf("%d", signal[33]);
        putchar(33);
        putchar(' ');}
        if(signal[38] != 0){printf("%d", signal[38]);
        putchar(38);
        putchar(' ');}
        if(signal[124] != 0){printf("%d", signal[124]);
        putchar(124);
        putchar(' ');}
        if(signal[62] != 0){printf("%d", signal[62]);
        putchar(62);
        putchar(' ');}
        if(signal[46] != 0){printf("%d", signal[46]);
        putchar(46);
    putchar(' ');}
    if(signal[45] != 0){printf("%d", signal[45]);
        putchar(45);}
        
    
return 0;
}