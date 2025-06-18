#include<stdio.h>
#include<string.h>
#include<math.h>
struct point{
    int m = 0;
    int n = 0;
    int sum = 99999;
};
void isort(point a[], int n){
    for(int i = 1; i < n; ++i){
        point key = a[i];
        int j = i - 1;
        while(j >= 0 && key.sum < a[j].sum){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main(){
    int m, n,count = 0;
    //int indexm[101], indexn[101], sum[101] = {};
    /*for(int i = 0; i < 101; ++i){
        indexm[i] = -1;
        indexn[i] = -1;
    }*/
    
    point pt[10000];
    int k = 0;
    scanf("%d%d",&m, &n);
    int martix[101][101] = {};
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%d", &martix[i][j]);
        }
    }

    for(int i = m - 1; i >= 0; --i){
        for(int j = n - 1; j >= 0; --j){
            if(j == n - 1 && i == m - 1){
                pt[k].m = m - 1;
                pt[k].n = n-1;
                pt[k].sum = martix[m-2][n-2]+martix[i][j];
                k++;
            }
            else if(j == 0 && i == m - 1){
                pt[k].m = m - 1;
                pt[k].n = 0;
                pt[k].sum = martix[m-2][1]+martix[i][j];
                k++;
            }
            else if(i == 0 && j == n-1){
                pt[k].m = 0;
                pt[k].n = n-1;
                pt[k].sum = martix[1][n-2]+martix[i][j];
                k++;
            }
            else if(i == 0 && j == 0){
                pt[k].m = 0;
                pt[k].n = 0;
                pt[k].sum = martix[1][1]+martix[i][j];
                k++;
            }
            else if(i == 0){
                pt[k].m = 0;
                pt[k].n = j;
                pt[k].sum = martix[1][j-1] + martix[1][j+1]+martix[i][j];
                k++;
            }
            else if(j == 0){
                pt[k].m = i;
                pt[k].n = 0;
                pt[k].sum = martix[i-1][1] + martix[i+1][1]+martix[i][j];
                k++;
            }
            else if(i == m-1){
                pt[k].m = i;
                pt[k].n = j;
                pt[k].sum = martix[i-1][j-1] +martix[i-1][j+1]+martix[i][j];
                k++;
            }
            else if(j == n-1){
                pt[k].m = i;
                pt[k].n = j;
                pt[k].sum = martix[i-1][j-1] + martix[i+1][j-1]+martix[i][j];
                k++;
            }
            else{
                pt[k].m = i;
                pt[k].n = j;
                pt[k].sum = martix[i][j]+martix[i-1][j-1]+martix[i-1][j+1]+martix[i+1][j-1]+martix[i+1][j+1];
                k++;
            }
        
        }
    }
    isort(pt, m*n);
    int min = pt[0].sum;
    for(int i = 0; i < m*n; ++i){
        if(pt[i].sum == min) count++; 
    }
    printf("%d %d\n", min, count);
    for(int i = 0; i < m*n; ++i){
        if(pt[i].sum == min) printf("%d %d\n", pt[i].m, pt[i].n);
    }
    return 0;
}