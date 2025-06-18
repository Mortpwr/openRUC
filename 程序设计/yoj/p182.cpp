/*#include<stdio.h>
int main(){
    int n = 0, ok = 0, count = 0;
    int ar[8] = {};
    scanf("%d", &n);
        count = 0;
        for(int a = 0; a <= 1 && count <= n; ++a){
            if(a){
                count++;
                ar[7] = ar[5] = 1;
            }
            else ar[7] = ar[5] = 0;
            for(int b = 0; b <= 1 && count <= n; ++b){
                if(b){
                count++;
                ar[1] = 1;
                }
                for(int c = 0; c <= 1 && count <= n; ++c){
                    if(c){
                    count++;
                    ar[6] = 1;
                    }
                    for(int d = 0; d <= 1 && count <= n; ++d){
                        if(d){
                        count++;
                        ar[1] = 0;
                        }
                        for(int e = 0; e <= 1 && count <= n ; ++e){
                            if(e){
                                count++;
                                if(a){
                                    ar[7] = ar[5] = 0;
                                }
                                else ar[7] = ar[5] = 1;
                            }
                            for(int f = 0; f <= 1 && count <= n; ++f){
                                if(f){ 
                                    ar[5] = ar[7] = 0;
                                    count++;
                                } 
                                for(int g = 0; g <= 1 && count <= n; ++g){
                                    if(!g){
                                        count++;
                                        ar[2] = 1;
                                    }
                                    for(int h = 0; h <= 1 && count <= n; ++h){
                                        if(a){
                                        count++;
                                        ar[7] = ar[5] = 1;
                                        }
                                        else ar[7] = ar[5] = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i <= 7; ++i){
        if(ar[i] == 1) ok++;
    }
    for(int i = 0; i <= 7; ++i){
        if(ok == 1 && ar[i] == 1) printf("%c", 'A'+i);
    }
    if(ok != 1) printf("DONTKNOW");
    
return 0;
}*/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int F1, F2, F3, F4, F5, F6, F7, F8, n, p, a;
    int shuzu1[8];
    cin >> n;
    
    for (int k = 1; k <= 8; k++)
    {
        F1 = (k == 6 || k == 8);
        F2 = (k == 2);
        F3 = (k == 7);
        F4 = (k != 2);
        F5 = (k != 6 && k != 8);
        F6 = (k != 6 && k != 8);
        F7 = (k != 3);
        F8 = (k == 6 || k == 8);
        shuzu1[k - 1] = F1 + F2 + F3 + F4 + F5 + F6 + F7 + F8;
        if (shuzu1[k - 1] == n)
        {
            p = p + 1;
            a = k;
        }
    }
    if (p == 1)
    {
        cout << char('A' - 1 + a) << endl;
    }
    else
        cout << "DONTKNOW" << endl;
    return 0;
}