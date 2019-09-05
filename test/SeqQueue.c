#include <stdio.h>
#include <stdlib.h>

#define MAX 8

typedef int DataType;
typedef struct SeqQueue{
    DataType data[MAX];
    int front;
    int rear;
}SQ;

// 初始化
void InitQueue(SQ * list){
    list->front = 0;
    list->rear = 0;
}

// 判列空
int EmptyQueue(SQ * list){
    if(list->rear == list->front){
        return 1;
    }else{
        return 0;
    }
}

// 判列满
int FullQueue(SQ * list){
    if((list->rear+1) % MAX == list->front){
        return 1;
    }else{
        return 0;
    }
}

// 入列
void PushQueue(SQ * list,DataType num){
    if(FullQueue(list)){
         printf("列满\n");
         exit(1);
    }else{
        list->rear = (list->rear+1) % MAX;
        list->data[list->rear] = num;
    }
}

// 出列
void PopQueue(SQ * list){
    if(EmptyQueue(list)){
         printf("列空\n");
         exit(1);
    }else{
        list->front = (list->front+1) % MAX;
        // 方便理解  data值改为0
        list->data[list->front] = 0;
    }
}

// 取队首元素
DataType TopQueue(SQ * list){
    if(EmptyQueue(list)){
        printf("列空\n");
        exit(1);
    }else{
        int i = (list->front+1) % MAX;
        return list->data[i];
    }
}

// 输出
void input(SQ * list){
    for(int i=0;i<MAX;i++){
         printf("第%d个元素，data为：%d\n",i,list->data[i]);
    }
     printf("\n");
}

int main(void){
    SQ CycQueue;
    SQ * list = &CycQueue;

    // 初始化
    InitQueue(list);
     printf("初始化后队首为：%d，队尾为：%d\n",list->front,list->rear);
     printf("\n");

    // 入队
    PushQueue(list,111);
    PushQueue(list,222);
    PushQueue(list,333);
    PushQueue(list,444);
    input(list);

    // 出队
    PopQueue(list);
    input(list);

    // 取队首元素
    DataType top = TopQueue(list);
     printf("队首元素为：%d\n",top);


    return 0;
}