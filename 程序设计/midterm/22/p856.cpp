#include<stdio.h>
int sum_digits(int a){
    int sum = 0;
    while(a > 0){
        sum += a%10;
        a = a/10;
    }
    return sum;
}
int main(){
    int model[100000] = {};
    int num[100000] = {};
    for(int i = 0; i < 100000; ++i){
        model[i] = sum_digits(i) + i;
    }     
    for(int i = 0; scanf("%d", &num[i]) != EOF; ++i);
    for(int i = 0; i < 100000 && num[i] != 0; ++i){
        int ok = 1;
        for(int j = 0; j < 100000; ++j){
            if(model[j] == num[i]){
                printf("%d\n", j);
                ok = 0;        
                break;
            }
        }
        if(ok) printf("0\n");
    }

return 0;
}