#include <iostream>
#include<stdio.h>
using namespace std;
int N;
int arr[100] = {}, total_cnt = 0;
bool isPlaceOK(int *a, int n, int c) {
    for (int i = 1; i <= n - 1; ++i) {
        if (a[i] == c || a[i] - i == c - n || a[i] + i == c + n)
            return false;
    }
    return true;
}
void addQueen(int *a, int n) {
    if (n > N) { 
        total_cnt++;
        return ;
    }
    for (int i = 1; i <= N; ++i){ 
        if (isPlaceOK(a, n, i)){
            a[n] = i;
            addQueen(a, n + 1);
        }
    }
}
int main(){
    scanf("%d", &N);
    addQueen(arr, 1);
    cout <<  total_cnt;
    return 0;
}
