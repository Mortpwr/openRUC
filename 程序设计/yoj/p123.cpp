#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
int step = 0;
int hanoi(int n, char start, char end){
    if(n == 0) return 0;
    char now = 0;
    int re;
    for(char i = 'a'; i < 'a'+3; ++i){
        if(i != start && i != end) now = i;
    }
    hanoi(n - 1, start, now);
    step++;
    printf("[step %d] move plate %d# from %c to %c\n", step, n, start, end);
    hanoi(n - 1, now, end);
    return step;
}
int main(){
    int n;
    scanf("%d", &n);
    int m = hanoi(n, 'a', 'c');
    printf("%d", m);     
return 0;
}