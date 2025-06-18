#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
int ary[5] = {5,4,3,2,1};
void quick_sort(int l, int r){
    int i = l, j = r, base = ary[l], t = 0;
    if(r > l){
        while(i < j){
            while(ary[j] >= base && i < j) j--;
            while(ary[i] <= base && i < j) i++;
            if(i < j){
                t = ary[i];
                ary[i] = ary[j];
                ary[j] = t;
            }
        }
        
        t = base;
        ary[l] = ary[i];
        ary[i] = t;
       
    }
}
int main(){
    quick_sort(0,4);
    for(int i = 0; i < 5; ++i){
        printf("%d ", ary[i]);
    }
return 0;
}