#include<stdio.h>
int main(){
    char* s[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int a, b;
    scanf("%d %d", &a, &b);
    if(b != 1) printf("%s\n%s", s[a%7], s[b-2]);
    else printf("%s\n%s", s[a%7], s[6]);
return 0;
}