#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct LinkTree{
    DataType data;
    struct LinkTree * lchild;
    struct LinkTree * rchild;
}LT;

// 初始化
void  InitTree(LT * tree){
    tree->data = 1;
    tree->lchild = NULL;
    tree->rchild = NULL;
}

// 输出
void input(LT * tree){
    printf("data：%d\n",tree->data);
}

// 先序遍历
void preorder(LT * tree){
    if(tree){
        input(tree);
        preorder(tree->lchild);
        preorder(tree->rchild);
    }
    return;
}

// 中序遍历
void inorder(LT * tree){
    if(tree){
        inorder(tree->lchild);
        input(tree);
        inorder(tree->rchild);
    }
    return;
}

// 后序遍历
void posorder(LT * tree){
    if(tree){
        posorder(tree->lchild);
        posorder(tree->rchild);
        input(tree);
    }
    return;
}

int main(void){
    LT * tree = (LT *)malloc(sizeof(LT));
    InitTree(tree);

    LT * node2 = (LT *)malloc(sizeof(LT));
    node2->data = 2;
    node2->lchild = NULL;
    node2->rchild = NULL;
    tree->lchild = node2;

    LT * node3 = (LT *)malloc(sizeof(LT));
    node3->data = 3;
    node3->lchild = NULL;
    node3->rchild = NULL;
    tree->rchild = node3;

    LT * node4 = (LT *)malloc(sizeof(LT));
    node4->data = 4;
    node4->lchild = NULL;
    node4->rchild = NULL;
    node2->lchild = node4;

    LT * node5 = (LT *)malloc(sizeof(LT));
    node5->data = 5;
    node5->lchild = NULL;
    node5->rchild = NULL;
    node2->rchild = node5;

    LT * node6 = (LT *)malloc(sizeof(LT));
    node6->data = 6;
    node6->lchild = NULL;
    node6->rchild = NULL;
    node3->lchild = node6;

    LT * node7 = (LT *)malloc(sizeof(LT));
    node7->data = 7;
    node7->lchild = NULL;
    node7->rchild = NULL;
    node3->rchild = node7;

    // 先序遍历
    printf("先序遍历：\n");
    preorder(tree);
    printf("\n");

    // 中序遍历
    printf("中序遍历：\n");
    inorder(tree);
    printf("\n");

    // 后序遍历
    printf("中序遍历：\n");
    posorder(tree);
    printf("\n");
}