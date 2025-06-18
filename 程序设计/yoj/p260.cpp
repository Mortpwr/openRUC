#include<stdio.h>
#include<algorithm>
struct search{
    int nth = 0;
    int count = 0;
};
search half_search(int a[], int n, int m){
    search num;
    int left = 0;
    int right = n-1;
    while(left <= right){
        num.count++;
        int middle = (left + right)/2;
        if(a[middle] == m){
            num.nth = middle;
            return num;    
        }
        if(a[middle] < m) left = middle + 1;
        if(a[middle] > m) right = middle - 1;
    }
    num.nth = -1;
    return num;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int s[n];
    for(int i = 0; i < n; ++i)
        scanf("%d", &s[i]);
    std::sort(s, s+n);
    search num = half_search(s, n, m);
    printf("%d\n%d", num.nth, num.count);
return 0;
}