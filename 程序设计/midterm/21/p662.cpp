#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
int main(){
    int t = 0, z = 0, c = 0;
    char name[100] = {};
    char x, g;
    int final = 0, compose = 0, paper = 0;
    scanf("%s%d%d %c %c%d", name, &final, &compose, &g, &x, &paper);
    int sum = 0;
    if(final > 80 && paper >= 1) sum+=6000;
    if(final > 85 && compose > 80) sum += 5000;
    if(final > 90) sum += 4000;
    if(final > 85 && x == 'Y') sum += 2500;
    if(compose > 80 && g == 'Y') sum += 950;
    printf("%s %d", name, sum);
return 0;
}