#include<stdio.h>// problem : beyond the limit of arrays, must consider the bound situation.
#include<algorithm>
struct student{
    int index = 0;
    int ave = 0;
};
void insertion_sort(student a[], int n){
    for(int i = 1; i < n; ++i){
        student key = a[i];
        int j = i - 1;
        while(j >= 0 && key.ave > a[j].ave){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main(){
    int N, position = 0, ok = 1;
    scanf("%d", &N);
    student num[1200];
    for(int i = 0; i < N; ++i) scanf("%d %d", &num[i].index, &num[i].ave);
    std::sort(num, num+N, [](student a, student b){return a.index <= b.index;});
    insertion_sort(num, N);
    for(int k = 0; k < N; ++k){
        position = k+1;
        if(num[k].ave != num[k+1].ave){
        printf("%d %d %d\n", k+1, num[k].index, num[k].ave);
        continue;
        }
        while(num[k].ave == num[k+1].ave && k < N){
            printf("%d %d %d\n", position, num[k].index, num[k].ave);
            k++;
        }
        if(k < N)printf("%d %d %d\n", position, num[k].index, num[k].ave); 
    }
return 0;
}