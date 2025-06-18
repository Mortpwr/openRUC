#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define LINE_BUF_SIZE 2048
typedef struct
{
    char isbn[11]; // 10 digits isbn
    char name[LINE_BUF_SIZE];
    char author[LINE_BUF_SIZE];
    char publisher[LINE_BUF_SIZE];
    int year;
} book_record_t;
typedef struct
{
    //指向一个存放所有图书数据的数组。
    //特别注意：函数调用时，本数组并未分配空间，需要你根据读入的数据合理地动态分配空间
    book_record_t * data;
    int size; //图书库中记录的条数（即数组元素的个数)
} book_manager_t;
int book_manager_load(book_manager_t * mgr, char * file_name){
    int n;
    FILE* f;
    f = fopen(file_name, "r");
    if(f == NULL) return -1;
    else{
        fscanf(f, "%d", &n);
        fgetc(f);
        fgetc(f);
        mgr->data = (book_record_t*)calloc(n, sizeof(book_record_t));
        mgr->size = n;
        for(int i = 0; i < n; ++i){
            fscanf(f,"%[^\n]",mgr->data[i].isbn);
            fgetc(f);
            fscanf(f,"%[^\n]",mgr->data[i].name);
            fgetc(f);
            fscanf(f,"%[^\n]",mgr->data[i].author);
            fgetc(f);
            fscanf(f,"%[^\n]",mgr->data[i].publisher);
            fgetc(f);
            fscanf(f,"%d",&mgr->data[i].year);
            fgetc(f);
            fgetc(f);
        }
        return 0;
    }
}


int main(){
          
return 0;
}