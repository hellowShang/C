#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

// 顺序栈   数组
#define MAX 10              // 栈容量
typedef int DataType;

// 定义结构体
typedef struct SeqStack{
    DataType data[MAX];     // 数组长度
    int top;
}stack;

// 初始化
void InitStack(stack * stk){
    stk ->top =0;
}

// 判栈空
int EmptyStack(stack * stk){
    if(stk->top == 0){
        return 1;
    }else{
        return 0;
    }
}

// 判栈满
int FullsStack(stack * stk){
    if(stk->top == MAX-1){
        return 1;
    }else{
        return 0;
    }
}

// 进栈、压栈
void PushStack(stack * stk,DataType x){
    if(FullsStack(stk)){     // 判断栈是否满
        printf("上溢\n");
        exit(1);
    }else{                  // 未满，则将x元素压入 ，top加1
        stk->top++;
        stk->data[stk->top] = x;
    }
}

// 出栈
DataType PopStack(stack * stk){
    if(EmptyStack(stk)){       // 判断栈是否空
        printf("下溢\n");
        exit(1);
    }else{
        DataType arr = stk->data[stk->top];         // 未空，则将栈顶元素出栈
        stk->top--;                                 //  top减1
        return arr;                                 // 返回元素
    }
}

int main(void){

    // 初始化
    stack ss;
    stack * stk = &ss;
    InitStack(stk);
    printf("初始化top:%d\n",stk->top);
    printf("\n");

    // 压栈
    PushStack(stk,11111);
    PushStack(stk,22222);
    PushStack(stk,33333);
    PushStack(stk,44444);
    PushStack(stk,55555);
    PushStack(stk,66666);
    PushStack(stk,77777);
    PushStack(stk,88888);
    PushStack(stk,99999);

    int i = stk->top;
    while(i>0){
        printf("压栈元素为： %d\n",stk->data[i]);
        i--;
    };
    printf("\n");

    // 出栈
    DataType num = PopStack(stk);
    printf("出栈元素为： %d\n",num);
    num = PopStack(stk);
    printf("出栈元素为： %d\n",num);
    num = PopStack(stk);
    printf("出栈元素为： %d\n",num);
    num = PopStack(stk);
    printf("出栈元素为： %d\n",num);
    num = PopStack(stk);
    printf("出栈元素为： %d\n",num);
    num = PopStack(stk);
    printf("出栈元素为： %d\n",num);
    num = PopStack(stk);
    printf("出栈元素为： %d\n",num);
    num = PopStack(stk);
    printf("出栈元素为： %d\n",num);
    num = PopStack(stk);
    printf("出栈元素为： %d\n",num);
    num = PopStack(stk);
    printf("出栈元素为： %d\n",num);
    printf("\n");

    return 0;
}
