#include<stdio.h>
int main(){
    int na, nb, nc, nd, ok = 0;
    scanf("%d%d%d%d", &na, &nb, &nc, &nd);
    int c[9] = {0, 120, 40, 85, 50, 100, 140, 70, 100};
    int ai = 0, bi = 0, ci = 0, di = 0;
    for(int i1 = 1; i1 <= 8; ++i1){
        if(na <= c[i1]) ai = i1;
        else ai = 0;
        for(int i2 = 1; i2 <= 8; ++i2){
            if(nb <= c[i2]) bi = i2;
            else bi = 0;
            for(int i3 = 1; i3 <= 8; ++i3){
                if(nc <= c[i3]) ci = i3;
                else ci = 0;
                for(int i4 = 1; i4 <= 8; ++i4){
                    if(nd <= c[i4]) di = i4;
                    else di = 0;
                    if((ai != bi)&&(ai != ci)&&(ai != di)&&(bi != ci)&&(bi != di)&&(ci != di)&&ai&&bi&&ci&&di){ 
                    ok = 1;
                    printf("%d %d %d %d\n", ai, bi, ci, di);
                    }
                }
            }
        }
    }
    if(!ok) printf("-1");
return 0;
}