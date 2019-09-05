#include <stdio.h>

#define MAX 8

typedef struct DataType{
    int age;
    char name[64];
    char sex;
}D;

typedef struct SeqList{
    D data[MAX];
    int lenght;
}SL;

// 插入
void InsertList(SL * list,D x,int i){
    if(i<1 || i>list->lenght+1){
        printf("位置错误\n");
    }

    if(list->lenght == MAX){
         printf("表已满\n");
    }

    for(int j=list->lenght;j>=i;j--){
        list->data[j] = list->data[j-1];
    }

    list->data[i-1] = x;

    list->lenght++;
}

// 删除
void DeleteList(SL * list,int i){
    if(i<1 || i> list->lenght+1){
         printf("位置错误\n");
    }

    for(int j=i;j<=list->lenght;j++){
        list->data[j-1] = list->data[j];
    }

    list->lenght--;
}

int main(void){
    SL Student = {{
        {11,"一号",'M'},
        {12,"二号",'F'},
        {13,"三号",'M'},
        {14,"四号",'F'},
        {15,"五号",'M'},
    },5};


    for(int i=0;i<MAX-1;i++){
        printf("Student的第%d个age为：%d，name为：%s，sex为：%c\n",i,Student.data[i].age,Student.data[i].name,Student.data[i].sex);
    }
    printf("表长为：%d\n",Student.lenght);
    printf("\n");

    // 插入
    D x = {900,"二十号",'M'};
    InsertList(&Student,x,4);

    for(int i=0;i<MAX-1;i++){
        printf("Student的第%d个age为：%d，name为：%s，sex为：%c\n",i,Student.data[i].age,Student.data[i].name,Student.data[i].sex);
    }
    printf("表长为：%d\n",Student.lenght);
    printf("\n");


    // 删除
    DeleteList(&Student,6);

    for(int i=0;i<MAX-1;i++){
        printf("Student的第%d个age为：%d，name为：%s，sex为：%c\n",i,Student.data[i].age,Student.data[i].name,Student.data[i].sex);
    }
    printf("表长为：%d\n",Student.lenght);
    printf("\n");


    return 0;
}