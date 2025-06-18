#include<stdio.h>
int main(){
    int n, num, ok = 1;
    int bukkit[2000000] = {};
    int negbukkit[2000000] = {};
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &num);
        if(num >= 0) bukkit[num]++;
        else negbukkit[-num]++;
    }
    for(int i = 0; i < 2000000; ++i) if(bukkit[i] > 1 || negbukkit[i] > 1) ok = 0;
    if(ok) printf("NO");
    else{
        for(int i = 2000000; i >= 0; --i){
            if(negbukkit[i] > 1){
                printf("%d:%d\n", -i, negbukkit[i]);
            }
        }
       
        for(int i = 0; i < 2000000; ++i){
            if(bukkit[i] > 1){
                printf("%d:%d\n", i, bukkit[i]);
            }
        }
    }
return 0;
}