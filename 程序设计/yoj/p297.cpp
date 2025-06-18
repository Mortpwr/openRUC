#include<stdio.h>
int main(){
    int d1, d2;
    scanf("%d%d",&d1, &d2);
    char* s[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    printf("%s\n", s[d1%7]);
    printf("%s", s[(7+((d2-2)%7))%7]);
return 0;
}