#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct LinkQueue{
    DataType data;
    struct LinkQueue * next;
}LQ;

typedef struct LinkNode{
    LQ * front;
    LQ * rear;
}link;

// 初始化
LQ * InitQueue(link * p){
    LQ * tmp = (LQ *)malloc(sizeof(LQ));
    tmp->next = NULL;
    p->front = tmp;
    p->rear = tmp;
}

// 判队空
int EmptyQueue(link * p){
    if(p->rear == p->front){
        return 1;
    }else{
        return 0;
    }
}

// 入列
void PushQueue(link * p,DataType x){
    LQ * tmp = (LQ *)malloc(sizeof(LQ));
    tmp->data = x;
    tmp->next = NULL;
    p->rear->next = tmp;
    p->rear = tmp;
}

// 出列
void PopQueue(link * p){
    if(EmptyQueue(p)){
        printf("队空\n");
        exit(1);
    }else{
        LQ * tmp = p->front->next;
        p->front->next = tmp->next;
        free(tmp);
    }
}


// 取队首元素
DataType FirstElement(link * p){
    if(!EmptyQueue(p)){
        LQ * tmp = p->front->next;
        return tmp->data;
    }
    printf("队空\n");
    exit(1);
}

// 输出
void input(link * p){
    LQ * tmp = p->front->next;
    while(tmp){
         printf("data：%d\n",tmp->data);
         tmp = tmp->next;
    }
    printf("\n");
}

int main(void){
    link queue;
    link * que = &queue;
    InitQueue(que);
    printf("初始化front：%p，rear：%p\n",que->front,que->rear);
    printf("\n");

    // 入列
    PushQueue(que,111);
    PushQueue(que,222);
    PushQueue(que,333);
    PushQueue(que,444);
    PushQueue(que,555);
    PushQueue(que,666);
    printf("入队后：\n");
    input(que);

    // 出队
    PopQueue(que);
    printf("出队后：\n");
    input(que);

    // 取队首元素
    DataType arr = FirstElement(que);
    printf("队首元素为： %d\n",arr);

    return 0;
}