#include<stdio.h>
struct song{
    int index = 0;
    int freq[16] = {};
    int euci = 0;
};
void insertion_sort(song a[], int n){
    song key;
    for(int i = 1; i < n; ++i){
        key = a[i];
        int j = i - 1;
        for(; j >= 0 && a[j].euci > key.euci; --j) a[j + 1] = a[j];
        a[j + 1] = key;
    }
}
void insertion_sort1(song a[], int n){
    song key;
    for(int i = 1; i < n; ++i){
        key = a[i];
        int j = i - 1;
        for(; j >= 0 && a[j].index > key.index; --j) a[j + 1] = a[j];
        a[j + 1] = key;
    }
}
int main(){
    int Q[16] = {};
    int n0, n, k, buf;
    scanf("%d", &n0);
    song music[150];
    for(int i = 0; i < n0; ++i){
        scanf("%d", &buf);
        for(int j = 0; j < 16; ++j){
            if(buf >= j*16 && buf <= (j+1)*16-1) Q[j]++;
        }
    }
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i){
        music[i].index = i;
        scanf("%d", &n0);
        for(int j = 0; j < n0; ++j){
            scanf("%d", &buf);
            for(int k = 0; k < 16; ++k){
            if(buf >= k*16 && buf <= (k+1)*16-1) music[i].freq[k]++;
            }
        }
        for(int m = 0; m < 16; ++m){
            music[i].euci += (music[i].freq[m]-Q[m])*(music[i].freq[m]-Q[m]);
        }
    }
    insertion_sort1(music, n);
    insertion_sort(music, n);
    for(int i = 0; i < k; ++i) printf("%d ", music[i].index);
return 0;
}