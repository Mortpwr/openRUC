#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
int total = 0;
int n;
int rec[11] = {};
struct booz{
    char a[105] = {};
    int ok = 1; }; booz bookarr[105]; bool is_ok(int person, booz book){ if(book.a[person] == '1' && book.ok) return true; return false; } void print_book(int i){ printf("B%d", i); } void divide_book(int person){
    if(person > n){
    for(int i = 1; i <= n; ++i){
        print_book(rec[i]);
    }
    putchar('\n');
    total++;
    return;
    } 
    for(int i = 1; i <= n; ++i){
        if(is_ok(person, bookarr[i])){
            bookarr[i].ok = 0;
            rec[person] = i;
            divide_book(person + 1); 
            rec[person] = 0;
            bookarr[i].ok = 1;
        }
    }
} void divide_book1(int person){ if(person > n){ total++; return; } for(int i = 1; i <= n; ++i){ if(is_ok(person, bookarr[i])){ bookarr[i].ok = 0; divide_book1(person + 1); bookarr[i].ok = 1; } } } int main(){ char s[105] = {}; scanf("%d", &n); for(int i = 1; i <= n; ++i){ scanf("%s", s);
        for(int j = 1; j <= n; ++j){
            bookarr[i].a[j] = s[j-1];
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            int t = bookarr[i].a[j];
            bookarr[i].a[j] = bookarr[j].a[i];
            bookarr[j].a[i] = t;
        }
    }
    divide_book1(1);
    if(total != 0) printf("%d\n", total);
    else printf("NO");
    divide_book(1);

return 0;
}