#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct LinkStack{
    DataType data;
    struct LinkStack * next;
}LS;

// 初始化
LS * InitStack(){
    LS * p = (LS *)malloc(sizeof(LS));
    p->next = NULL;
    return p;
}

// 判栈空
int EmptyStack(LS * stack){
    if(stack-> next == NULL){
        return 1;
    }else{
        return 0;
    }
}

// 压栈
void PushStack(LS * stack,DataType x){
    LS * tmp = (LS *)malloc(sizeof(LS));
    tmp->data = x;
    tmp->next = stack->next;
    stack->next = tmp;
}

// 输出
void input(LS * stack){
    LS * p = stack->next;
    while(p){
        printf("栈中数据为：%d\n",p->data);
        p = p->next;
    }
    printf("\n");
}

// 取栈顶元素
DataType TopStack(LS * stack){
    if(EmptyStack(stack)){
        printf("下溢\n");
        exit(1);
    }else{
        return stack->next->data;
    }
}

// 出栈
LS * PopStack(LS * stack){
     if(EmptyStack(stack)){
           printf("下溢\n");
           return stack;
     }else{
        LS * p = stack->next;
        stack->next = p->next;
        free(p);
        return stack;
     }
}

int main(void){
    // 初始化
    LS * stack = InitStack();

    // 压栈   
    PushStack(stack,11);
    PushStack(stack,22);
    PushStack(stack,33);
    PushStack(stack,44);
    // 输出
    input(stack);

    // 出栈
    PopStack(stack);
    PopStack(stack);
    // 输出
    input(stack);

    // 取栈顶元素
    DataType arr = TopStack(stack);
    printf("栈顶元素为：%d\n",arr);

    return 0;
}