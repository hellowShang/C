#include <stdio.h>
#include <stdlib.h>

    // 顺序队列   实现：数组  循环的

#define MAX 5
typedef int DataType;

// 定义结构
typedef struct CycQueue{
    DataType data[MAX];             // 数组长度
    int front,rear;                 // 定义队首、队尾
}CQ;

// 初始化      当前队列为空  <==>  队首、队尾都为0
void InitQueue(CQ * list){
    list->front = 0;                //  队首为0
    list->rear = 0;                 //  队尾为0
}

// 判列满
int FullQueue(CQ * list){
    if((list->rear+1) % MAX == list->front){            // 如果队尾+1  模  最大值  等于队首   证明：队列已满（一圈了）
        return 1;
    }else{
        return 0;
    }
}

// 入列       因是循环队列，故需取模运算
void EnQueue(CQ * list,DataType x){
    if(FullQueue(list)){                                // 判断队列是否满
        printf("列满\n");
        exit(1);
    }else{
        list->rear = (list->rear+1) % MAX;              // 否则 队尾+1 模  最大值(算出当前的插入位置)
        list->data[list->rear] = x;                     // 插入数据
    }
}

// 判列空
int EmptyQueue(CQ * list){
    if(list->rear  ==  list->front){                    // 判断队首是否等于队尾
        return 1;
    }else{
        return 0;
    }
}

// 出列   先进先出原则
void OutQueue(CQ * list){
    if(EmptyQueue(list)){                                               // 判断是否为空列
        printf("列空\n");
        exit(1);
    }else{
        list->front = (list->front+1) % MAX;                            // 数据出列
        list->data[list->front] = 0;                                    // 为方便理解  值改为0
    }
}

// 取列首元素
DataType getElement(CQ * list){
    if(EmptyQueue(list)){                                               // 判断是否为空列
        printf("列空\n");
        exit(1);
    }else{
        int i = (list->front+1) % MAX;
        return list->data[i];
    }
}

// 输出查看
void  input(CQ * list){
    for(int i=0;i<MAX;i++){
        printf("%d\n",list->data[i]);
    }
    printf("\n");
}

int main(void){
    CQ cq;
    CQ * list = &cq;

    // 初始化
    InitQueue(list);

    // 入列
    EnQueue(list,111);
    EnQueue(list,222);
    EnQueue(list,333);
    EnQueue(list,444);
//    EnQueue(list,555);
    printf("入列后，队列数据为：\n");
    input(list);

    // 出列
    OutQueue(list);
    OutQueue(list);
    OutQueue(list);
    OutQueue(list);
    printf("出列后，队列数据为：\n");
    EnQueue(list,555);
    EnQueue(list,666);
    EnQueue(list,777);
    EnQueue(list,888);
    OutQueue(list);
    EnQueue(list,999);
    input(list);

    // 取队首元素
    DataType element = getElement(list);
    printf("队首元素为：%d\n",element);

    return 0;
}