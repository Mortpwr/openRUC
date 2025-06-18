#include<stdio.h>
#include<string.h>
#define LEN 20

void clear(int a[]) {
  for(int i = 0; i < LEN; ++i) a[i] = 0;
}

void read(int a[]){
    static char s[LEN+1];
    clear(a);
    scanf("%s", s);
    int len = strlen(s);
    for(int i = 0; i <= len-1; ++i){
        a[len-i-1] = s[i]-'0';
    }

}

void print(int a[]) {
  int i;
  for (i = LEN - 1; i >= 1; --i)
    if (a[i] != 0) break;
  for (i; i >= 0; --i) 
  putchar(a[i] + '0');
  putchar('\n');
}

void add(int a[], int b[], int c[]){
    clear(c);
    for(int i = 0; i <= LEN; ++i){
        if((c[i] = a[i]+b[i]+c[i]) >= 10){
            c[i+1] = 1;
            c[i] = c[i]-10;
            }
    }
}

void sub(int a[], int b[], int c[]){
    clear(c);
    for(int i = 0; i <= LEN; ++i){
        if((c[i] = a[i]-b[i]+c[i]) < 0){
            c[i+1] = -1;
            c[i] = c[i]+10;
        }
    }
}

void mul_num(int a[], int b, int c[]){
    clear(c);
    for(int i = 0; i <= LEN; ++i){
        if((c[i] = a[i]*b+c[i]) >= 10){
            c[i+1] = c[i]/10;
            c[i] = c[i]%10;
        }
    }
}

void mul_mar(int a[], int b[], int c[]){
    clear(c);
    for(int i = 0; i <= LEN; ++i){
        for(int j = 0; j <= i; ++j){
            c[i] = a[j]*b[i-j]+c[i];
        }
        if((c[i] = c[i]/10+c[i]) >= 10){
            c[i+1] = c[i]/10;
            c[i] = c[i]%10;
        }
    }
}


int main(){
    int na[20],nb[20],nc[20];
    read(na);
    read(nb);
    mul_mar(na,nb,nc);
    print(nc);
return 0;
}
