#include<stdio.h>
#include<algorithm>
struct student{
    int index = 0;
    int total = 0;
};
int stat(int a[], int n, int m){
    int left = 0, right = n - 1;
    while(left <= right){
    int middle = (left + right)/2;
        if(a[middle] == m) return 1;
        if(a[middle] < m) left = middle + 1;
        if(a[middle] > m) right = middle - 1;
    }
    return 0;
}         // also can use array notation method
void insertion_sort(student a[], int n){
    for(int i = 1; i < n; ++i){
        student key = a[i];
        int j = i - 1;
        while(j >= 0 && key.total > a[j].total){
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main(){
    int n, m, k, count = 0;
    int pb[100];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &pb[i]);
    scanf("%d %d",&m, &k);
    student stu[100];
    std::sort(pb, pb+n);
    for(int i = 0; i < m; ++i){
        int p = 0, now = 0;
        scanf("%d %d", &stu[i].index, &p);
        for(int j = 0; j < p; ++j){
            scanf("%d", &now);
            stu[i].total += stat(pb, n, now);
        }
    }
    std::sort(stu, stu+m, [](student a, student b){return a.index < b.index;});
    insertion_sort(stu, m);
    for(count; count < m && k > 0; ++count){
        if(count < m-1 && stu[count].total != stu[count+1].total) k--;
        printf("%d ", stu[count].index);
    }
return 0;
}
