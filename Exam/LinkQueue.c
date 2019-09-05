#include <stdio.h>
#include <stdlib.h>

// 链队列

typedef int DataType;
typedef struct LinkQueueNode{
    DataType data;
    struct LinkQueueNode * next;
}LQ;

typedef struct LinkQueue{
    LQ * front;
    LQ * rear;
}link;

// 初始化
LQ * InitQueue(link * p){
    LQ * node = (LQ *) malloc(sizeof(LQ));
    node->next = NULL;
    p->front = node;
    p->rear  = node;
}

// 入队
void EnQueue(link * p,DataType x){
    // 分配内存
    LQ * tmp = (LQ *) malloc(sizeof(LQ));
    tmp->data = x;
    tmp->next = NULL;

    // 关联
    p->rear->next = tmp;
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

// 出队
void OutQueue(link * p){
    if(EmptyQueue(p)){
        printf("队空\n");
        exit(1);
    }else{
        LQ * tmp = p->front->next;
        p->front->next = tmp->next;
        if(tmp->next == NULL){
            p->rear = p->front;
        }
        free(tmp);
    }
}

// 取队首元素
DataType FrontElement(link * p){
    if(EmptyQueue(p)){
        printf("队空\n");
        exit(1);
    }else{
        LQ * tmp = p->front->next;
        return tmp->data;
    }
}

// 输出
void input(link * p){
    LQ * tmp = p->front->next;
    while(tmp){
        printf("%d\n",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(void){
    // 初始化
    link  lq;
    link * p = &lq;
    InitQueue(p);
    printf("初始化：\n");
    printf("%p\n",p->front);
    printf("%p\n",p->rear);
    printf("\n");

    // 入队
    EnQueue(p,11);
    EnQueue(p,22);
    EnQueue(p,33);
    EnQueue(p,44);
    printf("入队后：\n");
    input(p);

    // 出队
    OutQueue(p);
    OutQueue(p);
    printf("出队后:\n");
    input(p);

    // 取队首元素
    DataType arr = FrontElement(p);
    printf("队首元素为：%d\n",arr);

    return 0;
}