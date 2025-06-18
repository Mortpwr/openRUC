#include<stdio.h>
#include<algorithm>
struct para{
    int left = 0;
    int right = 0;
    int num = 0;
};
void insertion_sort(para a[], int n){
    for(int i = 1; i < n; ++i){
        para key = a[i];
        int j = i-1;
        while(j >= 0 && key.num > a[j].num){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
void task1(para a[], int n){
    for(int i = 0; i < n; ++i){
        if(a[i].num != 0 && a[i].right != 100) printf("[%2d,%3d): %d\n", a[i].left, a[i].right, a[i].num);
        else printf("[%2d,%3d]: %d\n", a[i].left, a[i].right, a[i].num);
    }
}
void task2(para a[],para b[], int n){
    if(b[0].num > 50){
        for(int i = 0; i < n; ++i){
            int notion = a[i].num*50/b[0].num; // 注意向下取整！
            if(a[i].right != 100) printf("[%2d,%3d):" , a[i].left, a[i].right);
            else printf("[%2d,%3d]:" , a[i].left, a[i].right);
            while(notion--) printf("*");
            printf("\n");
        }
    }
    else{
        for(int i = 0; i < n; ++i){
            int notion = a[i].num;
            if(a[i].right != 100) printf("[%2d,%3d):" , a[i].left, a[i].right);
            else printf("[%2d,%3d]:" , a[i].left, a[i].right);
            while(notion--) printf("*");
            printf("\n");
        }
    }
}
int main(){
    int n, m, g, score;
    scanf("%d%d%d",&n, &m, &g);
    int len = 100/m;
    para p[m];
    for(int i = 0; i < m; ++i){  // iterator !!!
        p[i].left = len*i;
        p[i].right = len*(i+1);
    }
    for(int i = 0; i < n; ++i){
        scanf("%d", &score);
        for(int j = 0; j < m; ++j)
            if(score >= p[j].left && score < p[j].right || (p[j].right == 100 && score == 100))
                p[j].num++;
        }
    para pcopy[m];
    for(int i = 0; i < m; ++i) pcopy[i] = p[i];
    std::sort(p, p+m, [](para a, para b){return a.right < b.right;});
    insertion_sort(p, m);
    if(g == 0){
        task1(p, m);
        printf("\n");
        task2(pcopy, p, m);
    }
    else if(g == 1) task1(p, m);
    else task2(pcopy, p, m);
return 0;
}