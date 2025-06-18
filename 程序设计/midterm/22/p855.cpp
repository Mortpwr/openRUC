#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#define maxn 200
char s[20] = {};
struct td{
    char st[maxn] = {};
};
int length(char a[], int max){
    int count = 0;
    for(int i = 0; i < max; ++i)
        if(a[i] != 0) count++;
    return count;
}

void write(char a[], char b[], int lenb){
    for(int i = 0; i < lenb; ++i){
        a[i + maxn - lenb] = b[i];
    }
}
int more_judge(char a[], char b[]){ //a > b
    for(int i = 0; i < maxn; ++i){
        if(a[i] != 0 || b[i] != 0){
            int indexa = 0, indexb = 0;
            for(int j = 0; j < 20; ++j){
                if(s[j] == a[i] && a[i] != 0) indexa = j;// zero mistak
                if(s[j] == b[i] && b[i] != 0) indexb = j;
            }
            if(indexa > indexb) return 1;
            if(indexa < indexb) return 0;
        }
    }
    return 0;
}
void copy(char a[], char b[]){ // no need
    for(int i = 0; i < maxn; ++i)
        a[i] = b[i];
}
void clear(char a[]){
    for(int i = 0; i < maxn; ++i) a[i] = 0;
}
void print(char a[]){
    for(int i = 0; i < maxn; ++i){
        if(a[i] != 0) printf("%c", a[i]);
    }
}
void insertion_sort(td a[], int n){
    for(int i = 1; i < n; ++i){
        td key;
        copy(key.st, a[i].st);
        int j = i - 1;
        while(j >= 0 && more_judge(key.st, a[j].st)){
            copy(a[j + 1].st,a[j].st);
            j--;
        }
        copy(a[j + 1].st, key.st);
    }
}
int main(){
    int n;
    long long final = 0;
    td mem[100];
    char s1[maxn] = {};
    scanf("%d %s", &n, s);
    int len = strlen(s);
    for(int i = 0; i < n; ++i){
        scanf("%s", s1);
        write(mem[i].st, s1, strlen(s1));
        clear(s1);
    }
    insertion_sort(mem, n);
    for(int i = 0; i < n; ++i){
        print(mem[i].st);
        printf(" ");
    }
    int lenfinal = length(mem[n-1].st, maxn);
    for(int i = 0; i < maxn; ++i){
        if(mem[n-1].st[i] != 0){
            int index = 0;
            for(int j = 0; j < 20; ++j){
                if(mem[n-1].st[i] == s[j]) index = j;
            }
            final += index*pow(len, maxn - 1 - i);
        }
    }
    printf("\n%lld", final);
return 0;
}