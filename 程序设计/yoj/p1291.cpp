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
int main(){
    int count = 0;
    for(int a = 0; a < 2; ++a){
        for(int b = 0; b < 2; ++b){
            for(int c = 0; c < 2; ++c){
                for(int d = 0; d < 2; ++d){
                    for(int e = 0; e < 2; ++e){
                        if(supposef(andf(a, b),andf(orf(c,andf(d,e)),andf(orf(!a, !b),supposef(d,andf(e,a))))) == true){
                            count++;
                        }
                        else continue;
                    }
                    

                    
                }
            }
            
        }

    }
    if(count == 32) printf("重言式");
    else if(count == 0) printf("矛盾式");
    else printf("可满足式");


return 0;
}