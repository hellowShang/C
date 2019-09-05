#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct LinkQueue{
    DataType data;
    struct LinkQueue * next;
}LQ;

typedef struct Queue{
    LQ * front;
    LQ * rear;
}Q;

// 初始化
LQ * InitQueue(Q  * link){
    LQ * node = (LQ *)malloc(sizeof(LQ));
    node -> next = NULL;

    link->front = node;
    link->rear = node;
    return node;
}

// 判空
int EmptyQueue(Q * link){
    if(link->rear == link->front){
        return 1;
    }else{
        return 0;
    }
}

// 入队
void PushQueue(Q * link,DataType x){
    LQ * tmp = (LQ *)malloc(sizeof(LQ));
    tmp ->data = x;
    tmp->next = NULL;

    link->rear->next = tmp;
    link->rear = tmp;
}

// 出队
void PopQueue(Q * link){
    if(EmptyQueue(link)){
         printf("列空\n");
         exit(1);
    }else{
        list->front
    }
}

// 取队首元素

// 输出
void input(Q * link){
    LQ * p = link->front->next;
    while(p){
         printf("data为：%d\n",p->data);
         p = p->next;
    }
     printf("\n");
}

int main(void){
    // 初始化
    Q link;
    Q * p = &link;
    InitQueue(p);
    printf("队首为：%p 队尾为：%p\n",p->front,p->rear);
    printf("\n");

    // 入队
    PushQueue(p,111);
    PushQueue(p,222);
    PushQueue(p,333);
    PushQueue(p,444);
    input(p);
}
