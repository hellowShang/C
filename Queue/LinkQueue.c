#include <stdio.h>
#include <stdlib.h>

// 链队列

typedef int DataType;
typedef struct LinkQueueNode{
    DataType data;                                          // 数据域
    struct LinkQueueNode * next;                            // 指针域
}LQ;

typedef struct LinkQueue{
    LQ * front;                                             // 队首指针
    LQ * rear;                                              // 队尾指针
}link;

// 初始化
LQ * InitQueue(link * p){
    LQ * node = (LQ *) malloc(sizeof(LQ));                  // 生成队列的头结点
    node->next = NULL;                                      // 队列头指针指向队列头结点
    p->front = node;                                        // 队列尾指针指向队列尾结点
    p->rear  = node;
}

// 入队
void EnQueue(link * p,DataType x){
    // 分配内存
    LQ * tmp = (LQ *) malloc(sizeof(LQ));
    tmp->data = x;                                          // data 赋值
    tmp->next = NULL;                                       // 指针域为空

    // 关联
    p->rear->next = tmp;                                    // 新结点链入队列尾
    p->rear = tmp;                                          // 尾指针指向新结点
}

// 判队空
int EmptyQueue(link * p){
    if(p->rear == p->front){                                // 头指针指向的地址与尾指针指向的地址相等的时候   队列即为空
        return 1;
    }else{
        return 0;
    }
}

// 出队
void OutQueue(link * p){
    if(EmptyQueue(p)){                                      // 出队时，先判空
        printf("队空\n");
        exit(1);
    }else{
        LQ * tmp = p->front->next;                          // tmp 指向队首结点
        p->front->next = tmp->next;                         // 修改头结点的指针域指向新的首结点
        if(tmp->next == NULL){                              // 无首结点时 队首、队尾都指向头结点
            p->rear = p->front;
        }
        free(tmp);                                          // 释放内存
    }
}

// 取队首元素
DataType FrontElement(link * p){
    if(EmptyQueue(p)){
        printf("队空\n");
        exit(1);
    }else{
        LQ * tmp = p->front->next;                          // 返回队首元素
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