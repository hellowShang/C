#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 16
typedef int DataType;

// 构建二叉树(数组)
typedef struct SeqTree{
    DataType arr[MAX];
}ST;

// 添加数据
void AddTree(ST * tree){
    int i = 1;
    char c;
    while(i<MAX){
        printf("请输入：\n");
        scanf("%c",&c);                             // 从键盘获取输入
        getchar();                                  // getchar函数 从标准输入里读取一个字符
        printf("输出的值为：%c\n",c);
        tree->arr[i] = c;                           // 数组赋值
        i++;
    }
}

// 输出
void input(ST * tree){
    int j = 0;
    while(j<MAX){
        printf("arr的第%d个下标，值为：%c\n",j,tree->arr[j]);
        j++;
    }
    printf("\n");
}

// 求双亲
 DataType ParentsTree(ST * tree,int i){
    if(i==1){                       // 判断输入值i是否为1
        return tree->arr[i];        // 返回根节点
    }else{
        int num = floor(i/2);       // 求父节点i/2  取输入的结点数的一半的最大整数      向下取整 floor
        return tree->arr[num];      // 返回双亲节点
    }
}

// 求左孩子
DataType LeftTree(ST * tree,int i){
    if(2*i>MAX-1){                   // 判断是否有左、右孩子
         printf("该节点无左孩子和右孩子\n");
         exit(1);
    }else{
        int num = 2*i;               // 求左孩子2*i    取输入结点的2倍
        return tree->arr[num];       // 返回左孩子
    }
}

// 求右孩子
DataType RightTree(ST * tree,int i){
    if(2*i+1>MAX-1){                 // 判断是否有右孩子
        printf("该节点无右孩子\n");
        exit(1);
    }else{
        int num = 2*i+1;             // 求右孩子 2*i+1  取输入结点的2倍加1
        return tree->arr[num];       // 返回右孩子
    }
}

int main(void){
    ST arr;
    ST * tree = &arr;

    // 添加数据
    AddTree(tree);
    input(tree);

    int num;
    printf("请输入要查找的结点：\n");
    scanf("%d",&num);

    DataType parents,left,right;
    // 求双亲
    parents = ParentsTree(tree,num);
    printf("双亲为：%c\n",parents);

    // 求左孩子
    left = LeftTree(tree,num);
    printf("左孩子为：%c\n",left);

    // 求右孩子
    right = RightTree(tree,num);
    printf("右孩子为：%c\n",right);

    return 0;
}