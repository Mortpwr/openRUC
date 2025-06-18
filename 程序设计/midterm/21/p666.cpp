#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
struct stu{
    int index = 0;
    int time = 0;
};
void insort(stu a[], int len){
    stu key;
    for(int i = 1; i < len; ++i){
        key = a[i];
        int j = i-1;
        while(j >= 0 && key.index < a[j].index){
            a[j+1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
void insortt(stu a[], int len){
    stu key;
    for(int i = 1; i < len; ++i){
        key = a[i];
        int j = i-1;
        while(j >= 0 && key.time < a[j].time){
            a[j+1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main(){
    stu student[1000];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &student[i].index, &student[i].time);
    }
    insort(student, n);
    insortt(student, n);
    int ele = 0;
    int day = 1;
    for(day; day <= 365; ++day){
        ele = 0;
        for(int j = 0; j < n; ++j){
            if(day - student[j].time >= 180) ele++; 
        }
        if(ele*10/n >= 3) break;
    }
    printf("%d\n", day);
    for(int i = 0; i <  ele; ++i){
        printf("%d %d\n", student[i].index, student[i].time);
    }

return 0;
}





// jian ge 180d zui zao pai xv zu zhi tiao jian 30%