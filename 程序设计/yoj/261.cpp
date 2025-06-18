#include <stdio.h>
#include <stdlib.h>

int power( int x, int y)
{
    int product = 1;
    for(int i = 1; i <= y; ++i){
        product = product*x;
    }
    if(y == 0) return 1;
    else return product;
}
int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d", power(x, y));
    return 0;

}