#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#define LEN 2005
int read(int a[]){
    static char s[LEN+1];
    scanf("%s", s);
    int len = strlen(s);
    if(s[0] != '-'){
        for(int i = 0; i < len; ++i){
            a[len-i-1] = s[i] - '0';
        }
        return 1;
    }
    else{
        for(int i = 1; i < len; ++i){
            a[len - i - 1] = s[i] - '0';
        }
        return 0;
    }
}
void print(int a[]) {
  int i;
  for(i = LEN - 1; i >= 0; --i) if (a[i] != 0) break;
  for(i; i >= 0; --i) putchar(a[i] + '0');
  putchar('\n');
}
void add(int a[], int b[], int c[]){
    for(int i = 0; i < LEN; ++i) c[i] = a[i] + b[i];
    for(int i = 0; i < LEN; ++i) 
        if(c[i] > 9){
            c[i+1]++;
            c[i] -= 10;
    }
}
void sub(int a[], int b[], int c[]){
    for(int i = 0; i < LEN; ++i) c[i] = a[i] - b[i];
    for(int i = 0; i < LEN; ++i) 
        if(c[i] < 0){
            c[i+1]--;
            c[i] += 10;
        }
}
int bigcomp(int a[], int b[]){
    int lena, lenb;
    for(int i = LEN; a[i] == 0; --i) lena = i;
    for(int i = LEN; b[i] == 0; --i) lenb = i;
    if(lena > lenb) return 1;
    else if(lena < lenb) return 0;
    else{
        for(int i = lena - 1; i >= 0; --i){
            if(a[i] > b[i]) return 1;
            else if(a[i] < b[i]) return 0;
        }
    }
    return 2;
}
int main(){
    int na[LEN] = {}, nb[LEN] = {}, nc[LEN] = {};
    char c;
    scanf("%c", &c);
    int np1 = read(na);
    int np2 = read(nb);
    int comp = bigcomp(na, nb);
    if(c == '+'){
        if(np1 && np2){
            add(na, nb, nc);
            print(nc);
        }
        else if(!np1 && !np2){
            add(na, nb, nc);
            putchar('-');
            print(nc);
        }
        else if(np1 == 0 && np2 == 1){
            if(comp == 2) putchar('0');
            else if(comp){
                sub(na, nb, nc);
                putchar('-');
                print(nc);
            }
            else{
                sub(nb, na, nc);
                print(nc);
            }
        }
        else{
            if(comp == 2) putchar('0');
            else if(comp){
                sub(na, nb, nc);
                print(nc);
            }
            else{
                sub(nb, na, nc);
                putchar('-');
                print(nc);
            }
        }
    }
    if(c == '-'){
        if(np1 && np2){
            if(comp == 2) putchar('0');
            else if(comp){
                sub(na, nb, nc);
                print(nc);
            }
            else{
                sub(nb, na, nc);
                putchar('-');
                print(nc);
            }
        }
        else if(!np1 && !np2){
            if(comp == 2) putchar('0');
            else if(comp){
                sub(na, nb, nc);
                putchar('-');
                print(nc);
            }
            else{
                sub(nb, na, nc);
                print(nc);
            }
        }
        else if(np1 == 0 && np2 == 1){
            add(na, nb, nc);
            putchar('-');
            print(nc);
        }
        else{
            add(na, nb, nc);
            print(nc);
        }
    }     
return 0;
}