#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef int DataType;

typedef struct SeqQueue{
    DataType data[MAX];
    int front,rear;
}SQ;

// 初始化
void InitQueue(SQ * que){
    que->front = 0;
    que->rear = 0;
}

// 判队空
int EmptyQueue(SQ * que){
    if(que->rear == que->front){
        return 1;
    }else{
        return 0;
    }
}

// 判队满
int FullQueue(SQ * que){
    if((que->rear+1) % MAX == que->front){
        return 1;
    }else{
        return 0;
    }
}

// 入队
void PushQueue(SQ * que,DataType x){
    if(FullQueue(que)){
         printf("队满\n");
         exit(1);
    }else{
        que->rear = (que->rear+1) % MAX;
        que->data[que->rear] = x;
    }
}

// 出队
DataType PopQueue(SQ * que){
    if(EmptyQueue(que)){
         printf("队空\n");
         exit(1);
    }else{
        que->front = (que->front+1) % MAX;
        que->data[que->front] = 0;
    }
}

// 取队首元素
DataType FirstQueue(SQ * que){
    if(EmptyQueue(que)){
        printf("队空\n");
        exit(1);
    }else{
        int num = (que->front+1) % MAX;
        return que->data[num];
    }
}

// 输出
void input(SQ * que){
    int i = 0;
    while(i<MAX){
         printf("第%d个元素，data：%d\n",i,que->data[i]);
         i++;
    }
     printf("\n");
}

int main(void){
    // 初始化
    SQ queue;
    SQ * que = &queue;
    InitQueue(que);
    printf("初始化front：%d,rear：%d\n",que->front,que->rear);
    printf("\n");

    // 入队
    PushQueue(que,111);
    PushQueue(que,222);
    PushQueue(que,333);
    PushQueue(que,444);
    PushQueue(que,555);
    PushQueue(que,666);
    PushQueue(que,777);
    PushQueue(que,888);
    PushQueue(que,999);
    printf("入队后：\n");
    input(que);

    // 出队
    PopQueue(que);
    PopQueue(que);
    PopQueue(que);
    PopQueue(que);
    PopQueue(que);
    PopQueue(que);
    PopQueue(que);
    printf("出队后：\n");
    input(que);

    // 取队首元素
    DataType arr = FirstQueue(que);
    printf("队首元素为： %d\n",arr);

    return 0;
}