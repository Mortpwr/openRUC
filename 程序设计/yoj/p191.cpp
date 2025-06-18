#include<stdio.h>// 注意编译器版本！ // 结构体数组的使用
#include<algorithm>
struct student
    {
        int index;
        int a[100] = {};
        int total = 0;
    };
void total(student num[], int score[],int n, int m){
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            if(num[i].a[j] >= 60) num[i].total += score[j];
        }
}
void insertion_sort(student a[], int n){
    for(int i = 1; i < n; ++i){
        student key = a[i];
        int j = i - 1;
        while(j >= 0 && key.total > a[j].total){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int score[200] = {};
    for(int i = 0; i < m; ++i) scanf("%d", &score[i]);
    student num[200];
    for(int i = 0; i < n; ++i){
        scanf("%d", &num[i].index);
        for(int j = 0; j < m; ++j){
            scanf("%d", &num[i].a[j]);
        }
    }
    total(num, score, n, m);
    std::sort(num, num+n, [](student a, student b){return a.index < b.index;});
    insertion_sort(num, n);
    for(int k = 0; k < n; ++k){
        printf("%d %d\n", num[k].index, num[k].total);
    }
return 0;
}