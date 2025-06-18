#include<stdio.h>
int main(){
    int N, a = 0, b = 0, c = 0, ok = 0;
    scanf("%d", &N);
    for(int i1 = 2; i1 <= 50; i1 += 2){
        for(int i2 = 1; i2 <= 20; ++i2){
            for(int i3 = 8; i3 <= 98; i3 += 2){
                if((i1 != i2) && (i2 != i3) && (i1 != i3)){
                    if((i1 < i3 && i1 > i2) || (i1 < i2 && i1 > i3)){
                        if(i3%10 == 8){
                            if((2*i1+6*i2+1*i3) > (N*0.9) && (2*i1+6*i2+1*i3) <= N){ // 九成和九成以上.....？
                                if((i1/2 < 5 && i2/10 == 0)) i1 = i1;
                                else {
                                    printf("%d %d %d\n", i1, i2, i3);
                                    ok = 1;
                                }
                        }
                    }
                }
            }
        }
    }
    }
    if(!ok) printf("no answer");
return 0;
}