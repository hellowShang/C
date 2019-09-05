#include <stdio.h>
#include <stdlib.h>

typedef int DateType;
typedef struct LinkTree{
    DateType data;
    struct LinkTree * lchlid;
    struct LinkTree * rchlid;
}LT;

// 初始化
void InitTree(LT * tree){
        tree->data = 1;
        tree->lchlid = NULL;
        tree->rchlid = NULL;
}

// 输出
void input(LT * tree){
    printf("data为：%d\n",tree->data);
}

// 先序遍历         根->左->右
void preorder(LT * tree){
    if(tree){
        input(tree);
        preorder(tree->lchlid);
        preorder(tree->rchlid);
    }
    return;
}

// 中序遍历         左->根->右
void inorder(LT * tree){
    if(tree){
        inorder(tree->lchlid);
        input(tree);
        inorder(tree->rchlid);
    }
    return;
}

// 后序遍历         左->右->根
void postorder(LT * tree){
    if(tree){
        postorder(tree->lchlid);
        postorder(tree->rchlid);
        input(tree);
    }
    return;
}

int main(void){
    LT * tree = (LT *)malloc(sizeof(LT));
    InitTree(tree);

    LT * node2 = (LT *)malloc(sizeof(LT));
    node2->data = 2;
    node2->lchlid = NULL;
    node2->rchlid = NULL;
    tree->lchlid = node2;

    LT * node3 = (LT *)malloc(sizeof(LT));
    node3->data = 3;
    node3->lchlid = NULL;
    node3->rchlid = NULL;
    tree->rchlid = node3;

    LT * node4 = (LT *)malloc(sizeof(LT));
    node4->data = 4;
    node4->lchlid = NULL;
    node4->rchlid = NULL;
    node2->lchlid = node4;

    LT * node5 = (LT *)malloc(sizeof(LT));
    node5->data = 5;
    node5->lchlid = NULL;
    node5->rchlid = NULL;
    node2->rchlid = node5;

    LT * node6 = (LT *)malloc(sizeof(LT));
    node6->data = 6;
    node6->lchlid = NULL;
    node6->rchlid = NULL;
    node3->lchlid = node6;

    LT * node7 = (LT *)malloc(sizeof(LT));
    node7->data = 7;
    node7->lchlid = NULL;
    node7->rchlid = NULL;
    node3->rchlid = node7;

    // 先序遍历
    printf("先序遍历：\n");
    preorder(tree);
    printf("\n");

    // 中序遍历
    printf("中序遍历：\n");
    inorder(tree);
    printf("\n");

    // 后序遍历
    printf("后序遍历：\n");
    postorder(tree);
    printf("\n");


    return 0;
}