#include<stdio.h>
#include<string.h>

char sopt[500] = {};
int countStr(char* p, char* a){
    int lenp = strlen(p), lena = strlen(a);
    int count = 0;
    for(int i = 0; i <= lenp - lena; ++i){
        int ok = 1;
        for(int j = 0; j < lena; ++j){
            if(*(p + i + j) != *(a + j)) ok = 0;
        }
        if(ok == 1){ 
            count++;
            i = i + lena - 1;
        }
    }
    return count;
}
char* deleteStr(char* p, char* a){
    int lenp = strlen(p), lena = strlen(a);int okm = 0;
    int count = 0;
    for(int i = 0; i <= lenp - lena; ++i){
        int ok = 1;
        for(int j = 0; j < lena; ++j){
            if(*(p + i + j) != *(a + j)) ok = 0;
        }
        if(ok == 1){ 
            count = i;
            okm = 1;
            break;
        }
    }
    if(okm != 0){
    for(int i = 0; i < count; ++i){
        sopt[i] = p[i];
    }
    for(int i = count + lena; i < lenp; ++i){
        sopt[i - lena] = *(p+i);
    }
    for(int i = 0; i < lenp; ++i){
        p[i] = 0;
    }
    for(int i = 0; i < lenp; ++i){
        p[i] = sopt[i];
    }}
    return sopt;
}
char* insertStr(char* p, char* a, char* b){
    int lenp = strlen(p), lena = strlen(a), lenb = strlen(b);
    int count = 0, okm = 0;
    for(int i = 0; i <= lenp - lena; ++i){
        int ok = 1;
        for(int j = 0; j < lena; ++j){
            if(*(p + i + j) != *(a + j)){ 
                ok = 0;
            }
        }
        if(ok == 1){ 
            count = i;
            okm = 1;
        }
    }
    if(okm){
        for(int i =0; i < count; ++i){
            sopt[i] = *(p + i);
        }
        for(int i = count; i < count + lenb; ++i){
            sopt[i] = *(b + i - count);
        }
        for(int i = count; i < lenp; ++i){
            sopt[i + lenb] = *(p + i);
        }
    }
    else;
    for(int i = 0; i < strlen(sopt); ++i){
        p[i] = sopt[i];
    }
    return sopt;
}
char* replaceStr(char* p, char* a, char* b){
    int lenp = strlen(p), lena = strlen(a), lenb = strlen(b);
    int countl = 0, index = 0, countr = 0;
    for(int i = 0; i <= lenp - lena; ++i){
        int ok = 1;
        for(int j = 0; j < lena; ++j){
            if(*(p + i + j) != *(a + j)){ 
                ok = 0;
            }
        }
        if(ok == 1){ 
            countr = i;
            for(int m = countl; m < countr; ++m){
                sopt[index] = *(p + m);
                index++;
            }
            for(int m = 0; m < lenb; ++m){
                sopt[index] = *(b + m);
                index++;
            }
            i = i + lena - 1;
            countl = i + 1;
        }
    }
    for(int i = countl; i < lenp; ++i){
        sopt[index] = *(p + i);
        index++;
    }
    return sopt;
}
char parseCmd(char* s, char* str1, char* str2){
    for(int i = 0; i < 200; ++i){
        *(str1+i) = 0;
        *(str2+i) = 0;
    }
    const char blank[2] = " ";
    int k = 2, count1 = 0, count2 = 0;
    char* a;
    a = strtok(s, blank);
    char cmd = *a;
    for(k; *(s+k) != ' ' && *(s+k) != 0 && *(s+k) != '\n'; ++k){
        *(str1+count1) = *(s+k);
        count1++;
    }
    k++;
    for(k; *(s+k) != 0; ++k){
        *(str2+count2) = *(s+k);
        count2++;
    }
    return cmd;
}
int main()
{
	char s[500],cmdstr[500], str1[500], str2[500], cmd;

    fgets(s, 500, stdin);
	fgets(cmdstr, 500, stdin);
    cmd = parseCmd(cmdstr, str1, str2);

    switch ( cmd )
    {
    case 'C':
        printf("%d\n", countStr(s, str1));
        break;
    case 'D':
        deleteStr(s, str1);
        printf("%s\n", s);
        break;
    case 'I':
        insertStr(s, str1, str2);
        printf("%s\n", s);
        break;
    case 'R':
        printf("%s\n", replaceStr(s, str1, str2));
        break;
    }
    return 0;
    
}
