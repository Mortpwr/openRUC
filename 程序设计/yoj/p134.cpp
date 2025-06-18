#include<stdio.h>
int main(){
    int N, a, b, c, ok = 0, count = 0;
    scanf("%d", &N);
    int s[10000], an[4], jn[4];
    for(int m = 1000; m < 10000; ++m){
        s[m] = 1;
    }
    for(int i = 1; i <= N; ++i){
        scanf("%d %d %d", &a, &b, &c);
        for(int a1 = 0; a1 < 4; ++a1){
            an[a1] = a%10;
            a = a/10;
        }
        int j = 1000;
        for(j; j < 10000; ++j){ //////!!!!! condition judgement before the iteration!!!!
            if(s[j] == 0) continue;
            int num = j;
            for(int j1 = 0; j1 < 4; ++j1){
            jn[j1] = num%10;
            num = num/10;
            }
            int countc = 0, w = 0;
            for(int n = 0; n < 4; ++n){
                if(an[n] == jn[n]) countc++;
                }
            for(int d = 0; d <= 9; ++d){
                    int n1 = 0, n2 = 0;
                    for(int i2 = 0; i2 < 4; ++i2){ //配对后不能再配对
                        if(an[i2] == d) n1++;
                        if(jn[i2] == d) n2++;
                    }
                    if(n1 <= n2) w += n1; //数学视角观察后写程序
                    else w += n2;
                }
               // printf(" %d-%d ", w, b);
            if(!(c == countc && b == w)) s[j] = 0; 
            //if(!(c == countc && b == w-countc) && i >= 4) printf(" %d-%d ",i, j);
            //else if (i >= 3) printf(" %d-%d ",i, j);
        }
        //if(i >= 3) printf("* %d %d %d *", a, b, c);
    }
    for(int m = 1000; m < 10000; ++m){
        if(s[m] == 1){
        ok = m;
        count++;
        }
    }
    if(count == 1) printf("%d",ok);
    else printf("Not Sure");
return 0;
}
