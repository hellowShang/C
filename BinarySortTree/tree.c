#include <stdio.h>
#include <stdlib.h>

typedef int DateType;
typedef struct binarySortTree{
    DateType key;
    struct binarySortTree * lchild;
    struct binarySortTree * rchild;
}BST;

// 初始化
BST * initTree(){
    BST * tmp = (BST *)malloc(sizeof(BST));
    tmp->key = 38;
    tmp->lchild =NULL;
    tmp->rchild =NULL;
}

// 添加数据
void addTree(BST * tree){
    BST * node1 = (BST *)malloc(sizeof(BST));
    node1->key = 18;
    node1->lchild = NULL;
    node1->rchild = NULL;
    tree->lchild = node1;

    BST * node2 = (BST *)malloc(sizeof(BST));
    node2->key = 50;
    node2->lchild = NULL;
    node2->rchild = NULL;
    tree->rchild = node2;

    BST * node3 = (BST *)malloc(sizeof(BST));
    node3->key = 7;
    node3->lchild = NULL;
    node3->rchild = NULL;
    node1->lchild = node3;

    BST * node4 = (BST *)malloc(sizeof(BST));
    node4->key = 30;
    node4->lchild = NULL;
    node4->rchild = NULL;
    node1->rchild = node4;

    BST * node5 = (BST *)malloc(sizeof(BST));
    node5->key = 76;
    node5->lchild = NULL;
    node5->rchild = NULL;
    node2->rchild = node5;

    BST * node6 = (BST *)malloc(sizeof(BST));
    node6->key = 20;
    node6->lchild = NULL;
    node6->rchild = NULL;
    node4->lchild = node6;

    BST * node7 = (BST *)malloc(sizeof(BST));
    node7->key = 35;
    node7->lchild = NULL;
    node7->rchild = NULL;
    node4->rchild = node7;

    BST * node8 = (BST *)malloc(sizeof(BST));
    node8->key = 70;
    node8->lchild = NULL;
    node8->rchild = NULL;
    node5->lchild = node8;
}

// 输出
void input(BST * tree){
    printf("key：%d\n",tree->key);
}

// 中序遍历
void InOrder(BST * tree){
    BST * p = tree;
    if(p){
        InOrder(p->lchild);
        input(tree);
        InOrder(p->rchild);
    }
    return;
}

// 查找
BST * SearchTree(BST * tree,DateType key){
    BST * p = tree;
    if(p == NULL){
         printf("空树\n");
         exit(0);
    }else if(p->key == key){                        // 查找的key等于树中的key
        return p;                                   // 返回结点
    }else if(key > p->key){                         // 查找的key大于树中的key
        SearchTree(p->rchild,key);                  // 继续在右子树查找
    }else{                                          // 查找的key小于树中的key
        SearchTree(p->lchild,key);                  // 继续在左子树查找
    }
}

// 插入前的查找
BST * SearchTree1(BST * tree,DateType key,BST * f){
        BST * p = tree;
        if(p == NULL){
             return NULL;
        }else if(p->key == key){                            // 查找的key等于树中的key
            return p;                                       // 返回结点
        }else if(key > p->key){                             // 查找的key大于树中的key
            SearchTree1(p->rchild,key,p);                   // 继续在右子树查找
        }else{                                              // 查找的key小于树中的key
            SearchTree1(p->lchild,key,p);                   // 继续在左子树查找
        }
}

// 插入
int InsertTree(BST * tree,DateType key){
       BST * f = NULL;
       BST * p = SearchTree1(tree,key,f);
       if(p == NULL){

        printf("f->key:%d\n",f->key);
            BST * tmp = (BST *)malloc(sizeof(BST));
            tmp->key = key;
            tmp->lchild = NULL;
            tmp->rchild = NULL;
            if(f == NULL){
                tree = tmp;
            }else if(key < f->key){
                f->lchild = p;
            }else{
                f->rchild = p;
            }
            return 1;
       }else{
            return 0;
       }
}

int main(void){
    // 初始化
    BST * tree = initTree();
    printf("初始化为：\n");
    printf("key：%d，lchild：%p，rchild：%p\n",tree->key,tree->lchild,tree->rchild);
    printf("\n");

    // 添加数据
    addTree(tree);


    // 中序遍历
    InOrder(tree);
    printf("\n");

    // 查找
//    int num;
//    printf("请输入要查找的值：\n");
//    scanf("%d",&num);
//    getchar();
//    BST * p = SearchTree(tree,num);
//    printf("你要查找的key为：%d,查找的key位置为：%p\n",num,p);

    // 插入
    int k = InsertTree(tree,68);
    if(k){
        printf("插入成功\n");
        printf("\n");

        // 中序遍历
        printf("中序遍历\n");
        InOrder(tree);
        printf("\n");
    }else{
        printf("插入失败\n");
    }


    return 0;
}