#include <stdio.h>
#include <stdlib.h>

// 链栈
typedef int DataType;

typedef struct LinkStack{
    DataType data;
    struct LinkStack * next;
}LS;

// 初始化
LS * InitStack(){
    LS * p = (LS *) malloc(sizeof(LS));
    p->next = NULL;
    return p;
}

// 压栈 进栈
LS * PushStack(LS * head,DataType x){
    LS * p = (LS *) malloc(sizeof(LS));     // 分配内存
    p->data = x;                            // 栈的data域赋值
    p->next = head->next;                   // 栈的新结点的指针域 指向 原先的栈顶元素
    head->next = p;                         // 原先的头结点 指向 新的栈顶结点
}

// 判栈空
int EmptyStack(LS * head){
    if(head->next == NULL){
        return 1;
    }else{
        return 0;
    }
}

// 出栈
LS * PopStack(LS * head){
     if(EmptyStack(head)){                  // 判断栈是否为空
           printf("下溢\n");
           return head;
     }else{
        LS * p = head->next;                // p  指向   栈顶结点
        head->next = p->next;               // 原栈顶的指针域  指向   新的栈顶结点
        free(p);                            // 释放原栈顶结点空间
        return head;
     }
}

// 取栈顶元素
DataType TopStack(LS * head){
    if(EmptyStack(head)){
        printf("下溢\n");
        exit(1);
    }else{
        return head->next->data;
    }
}

// 输出
void input(LS * head){
    LS * p = head->next;
    while(p){
        printf("栈中数据为：%d\n",p->data);
        p = p->next;
    }
    printf("\n");
}

int main(void){
    // 初始化
    LS * head = InitStack();

    // 压栈
    PushStack(head,11);
    PushStack(head,22);
    PushStack(head,33);
    PushStack(head,44);
    // 输出
    input(head);

    // 出栈
    PopStack(head);
    PopStack(head);
    // 输出
    input(head);

    // 取栈顶元素
    DataType arr = TopStack(head);
    printf("栈顶元素为：%d\n",arr);

    return 0;
}