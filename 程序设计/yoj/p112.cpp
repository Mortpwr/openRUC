#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int bisearch( int ary[], int left, int right, int num )
{
    printf("search %d from %d to %d", num, left, right );
    cout << endl;
    if(left > right) return -1;
    else{
        int middle = (left + right)/2;
        if(ary[middle] == num) return middle;
        else if(ary[middle] > num) return bisearch(ary, left, middle-1, num);
        else return bisearch(ary, middle+1, right, num);
    }
}
int main()
{
    int n, array[10000], i, num;
    scanf("%d", &n);
    scanf("%d", &num);
    for (i = 0; i < n; i ++ )
    {
        scanf("%d", &array[i]);
    }
    printf( "%d", bisearch(array, 0, n-1, num));
    cout << endl;
    return 0;
}    

