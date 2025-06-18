#include<stdio.h>
struct vp{
    int interval = 0;
    double rate = 0;
};
int main(){
    int n, total;
    double sum = 0;
    scanf("%d", &n);
    vp vpm[150];
    for(int i = 0; i < n; ++i) scanf("%d %lf", &vpm[i].interval, &vpm[i].rate);
    scanf("%d", &total);
    if(total < 0) printf("NO");
    else if(n == 0) printf("0.00");
    else if(n == 1) printf("%.2lf", total* vpm[0].rate);
    else{
        while(total > 0){
            for(int i = 1; i < n-1; ++i){
                if(total > vpm[i-1].interval && total <= vpm[i].interval){
                    int now = total - vpm[i-1].interval;
                    sum += now*vpm[i].rate;
                    total -= now;
                }
                else if(total > vpm[n-2].interval){
                    int now = total - vpm[n-2].interval;
                    sum += now*vpm[n-1].rate;
                    total -= now;
                }
                else if(total <= vpm[0].interval){
                    sum += vpm[0].rate*total;
                    total = 0;
                }
            }
        }
        printf("%.2lf", sum);
    }
    
return 0;
}