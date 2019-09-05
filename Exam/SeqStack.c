#include <stdio.h>
#include <stdlib.h>

#define MAX 8

typedef int DataType;
typedef struct SeqStack{
    DataType data[MAX];
    int top;
}SS;

// 初始化
SS * InitStack(SS * stack){
    stack->top = 0;
}

// 判栈空
int EmptyStack(SS * stack){
    if(stack->top == 0){
        return 1;
    }else{
        return 0;
    }
}

// 判栈满
int FullStack(SS * stack){
    if(stack->top == MAX-1){
        return 1;
    }else{
        return 0;
    }
}

// 进栈
void PushStack(SS * stack,DataType x){
    if(FullStack(stack)){
         printf("栈满\n");
         exit(1);
    }else{
        stack->top++;
        stack->data[stack->top] = x;
    }
}

// 出栈
DataType PopStack(SS * stack){
    if(EmptyStack(stack)){
         printf("栈空\n");
         exit(1);
    }else{
        DataType pop =  stack->data[stack->top];
        stack->top--;
        return pop;
    }
}

int main(void){
    SS ss;
    SS * stack = &ss;
    // 初始化
    SS * init = InitStack(stack);
    printf("初始化后top为：%d\n",init->top);

    // 压栈
    for(int i=1;i<MAX-1;i++){
        PushStack(stack,i*100);
    }

    // 输出
    int j = stack->top;
    while(j>0){
        printf("top为：%d，data为：%d\n",j,stack->data[j]);
        j--;
    }
    printf("\n");

    // 出栈
    DataType pop = PopStack(stack); printf("出栈元素为：%d\n",pop); printf("\n");
    pop = PopStack(stack); printf("出栈元素为：%d\n",pop); printf("\n");
    pop = PopStack(stack); printf("出栈元素为：%d\n",pop); printf("\n");

    return 0;
}