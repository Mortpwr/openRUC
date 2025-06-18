#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
class square
{
    public:
    struct po{
        double x;
        double y;
    };
    po point1, point2;
    double length;
    double width;
    double set(double x1, double y1, double x2, double y2);
    double area(void);
    double cir(void);
};
double square::set(double x1, double x2, double y1, double y2){
    point1.x = x1;
    point1.y = y1;
    point2.x = x2;
    point2.y = y2;
    length = abs(x1-x2);
    width = abs(y1-y2);
}
double square::area(void){
    return length*width;
}
double square::cir(void){
    return 2*(length + width);
}
int main(){
    square s1, s2;
    double a, b, c, d;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    s1.set(a, b, c, d);
    
return 0;
}