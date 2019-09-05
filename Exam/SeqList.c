#include <stdio.h>
#include <stdlib.h>

int MAX=8;
// 定义数组
typedef struct DataType{
    int age;
    char name[4];
    char sex;
}D;
// 定义结构体
typedef struct SeqList{
    D data[8];
    int lenght;
}SL;

// 插入
void InsertList(SL * list,D x,int i){
    if(list->lenght == MAX){
        printf("表满了\n");
        exit(1);
    }
    if(i<1 || i> list->lenght+1){
        printf("位置错误\n");
        exit(1);
    }

    // 依次后移
    for(int j=list->lenght;j<=i;j--){
        list->data[j] = list->data[j-1];
    }

    // 新元素插入
    list->data[i-1] = x;

    // 表长+1
    list->lenght++;
}

// 删除
void DeleteList(SL * list,int i){
    if(i<1 || i>list->lenght+1){
        printf("位置错误\n");
        exit(1);
    }

    for(int j=i;j<=list->lenght;j++){
        list->data[j-1] = list->data[j];
    }

    list->lenght--;
}

int main(void){
    // 添加数据
SL link= {{
             {11,"壹",'F'},
             {12,"贰",'M'},
             {13,"叁",'M'},
             {14,"肆",'F'},
             {15,"伍",'M'},
         },5};
    SL * list = &link;

    // 输出
    for(int i=0;i<=MAX;i++){
        printf("添加数据后顺序表age为：%d，name为：%s，sex为：%c\n",link.data[i].age,link.data[i].name,link.data[i].sex);
        printf("\n");
    }
    printf("表长为：%d\n",list->lenght);

    printf("***************************************************************************\n");
    printf("\n");

    // 插入
    D x = {16,"陆",'M'};
    InsertList(list,x,3);


    // 输出
    for(int i=0;i<=MAX;i++){
        printf("添加数据后顺序表age为：%d，name为：%s，sex为：%c\n",link.data[i].age,link.data[i].name,link.data[i].sex);
        printf("\n");
    }
    printf("表长为：%d\n",list->lenght);

    printf("***************************************************************************\n");
    printf("\n");

    // 删除
    DeleteList(list,5);

    // 输出
    for(int i=0;i<=MAX;i++){
        printf("添加数据后顺序表age为：%d，name为：%s，sex为：%c\n",link.data[i].age,link.data[i].name,link.data[i].sex);
        printf("\n");
    }
    printf("表长为：%d\n",list->lenght);

    printf("***************************************************************************\n");
    printf("\n");


    return 0;
}