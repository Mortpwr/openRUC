#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
struct op1{
    int index = 0;
    int p = 0;
    int r[100] = {};
};
struct se{
    int a[50] = {};
    int sum = 0;
};
struct ele{
    int nth = 0;
    int now = 0;
};
void insort(op1 a[], int len){
    for(int i = 1; i < len; ++i){
        op1 key;
        key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j].p < key.p){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
void insortse(se a[], int len){
    for(int i = 1; i < len; ++i){
        se key;
        key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j].sum < key.sum){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
ele searchr(op1 a, int v){
    ele final;
    for(int i = 0; i < v; ++i){
        if(a.r[i] > final.now){
            final.now = a.r[i];
            final.nth = i;
        }
    }
    return final;
}
void copy(se a[], se b[], int len){
    for(int i = 0; i < len; ++i){
        a[i] = b[i];
    }
}
int main(){
    int v, l, k, count = 0;
    op1 word[60];
    op1 wordcopy[60];
    se sentence[60];
    scanf("%d%d%d", &v, &l, &k);
    for(int i = 0; i < v; ++i){
        scanf("%d", &word[i].p);
        word[i].index = i;
    }
    for(int i = 0; i < v; ++i){
        for(int j = 0; j < v; ++j){
            scanf("%d", &word[i].r[j]);
        }
    }
    for(int i = 0; i < v; ++i){
        wordcopy[i] = word[i];
    }
    insort(word, v);
    se sentenceb[1000];
    se sentence0[1000];
    ele buffer;
    for(int i = 0; i < k; ++i){
            sentenceb[i].a[0] = word[i].index;
            sentenceb[i].sum += word[i].p;
        }
    int j = 1;
    while(j < l){
        int iter = 0;
        for(int i = 0; i < k; ++i){
            for(int p = 0; p < v; ++p){
            buffer = searchr(wordcopy[sentenceb[iter].a[j-1]], v);
            sentenceb[iter].sum += buffer.now;
            sentenceb[iter].a[]
            iter++;
                }
        }
        insortse(sentenceb, k);
        copy(sentence, sentenceb, k);
        j++;
    }
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < l; ++j){
            printf("%d ", sentence[i].a[j]+1);
        }
        printf("\n");
    }
return 0;
}
//为什么不排序？
