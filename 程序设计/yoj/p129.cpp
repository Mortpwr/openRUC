#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
int digit[32] = {};// dao xv
void digit_d(int n, int len){
    memset(digit, -1, sizeof(digit));
    for(int i = 0; n > 0; ++i){
        digit[i] = n%len;
        n = n / len;
    }
}
int to_ten(char* s, char* digit){
    int a = 0, lend = strlen(digit), lens = strlen(s);
    for(int i = lens - 1; i >= 0; --i){
        for(int j = 0; j < lend; ++j){
            if(s[i] == digit[j]) a += j * pow(lend, lens - i - 1);
        }
    }
    return a;
}
int main(){
    int n = 0, k = 1, a = 0;
    scanf("%d", &n);
    char alien[100] = {}, source[100] = {}, target[100] = {};
    while(n--){
        memset(alien, 0, sizeof(alien));
        memset(source, 0, sizeof(source));
        memset(target, 0, sizeof(target));
        memset(digit, -1, sizeof(digit));
        scanf("%s %s %s", alien, source, target);
        a = to_ten(alien, source);
        digit_d(a, strlen(target));
        printf("Case #%d: ", k);
        k++;
        for(int i = 31; i >= 0; --i){
            if(digit[i] != -1) putchar(target[digit[i]]);
        }
        putchar('\n');
    }
return 0;
}