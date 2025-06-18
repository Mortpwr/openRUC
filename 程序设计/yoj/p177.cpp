#include<stdio.h>
int sum_digits(int a){
    int sum = 0;
    while(a > 0){
        sum += a%10;
        a = a/10;
    }
    return sum;
}

void insertion_sort(int a[], int n){
    for(int i = 1; i < n; ++i){
        int key = a[i];
        int j = i - 1;
        while(a[j] > key && j >= 0){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main(){
    int n, k, count = 0;
    int ok[200] = {};
    int s[200] = {}; 
    scanf("%d %d",&n, &k);
    for(int i = 0; i < n; ++i){
        scanf("%d", &s[i]);
    }
    insertion_sort(s, 200);
    for(int i = 0; i < 200; ++i){
        if(s[i] != 0){
            int sum = 0;
            sum = sum_digits(s[i]);
            if(sum % k == 0){
            ok[i] = 1;
            count++;
            }
        }
    }
    printf("%d\n", count);
    for(int i = 0; i < 200; ++i){
        if(ok[i]) printf("%d\n", s[i]);
    }
return 0;
}