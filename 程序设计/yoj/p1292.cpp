#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
int supposef(int a, int b){
    if(a == true && b == true) return true;
    else if(a == true && !b == true) return false;
    else if(a == false) return true;
}
int andf(int a, int b){
    if(a == true && b == true) return true;
    else return false;

}
int orf(int a, int b){
    if(!a == true && !b == true) return false;
    else return true;
}
int xorf(int a, int b){
    if(a == b) return true;
    else return false;
}
int main(){
    int ok = 1;
    for(int a = 0; a < 2; ++a){
        for(int b = 0; b < 2; ++b){
            for(int c = 0; c < 2; ++c){
                for(int d = 0; d < 2; ++d){
                    for(int e = 0; e < 2; ++e){
                        if(!xorf(andf(andf(andf(a,b),c), supposef(d,e)) , orf( orf( andf(a,d), andf(b,e)),andf(c,d) ))){
                            ok = 1;
                        }
                        else continue;
                    }
                    

                    
                }
            }
            
        }

    }
    if(ok) printf("等价");
    else printf("不等价");

return 0;
}