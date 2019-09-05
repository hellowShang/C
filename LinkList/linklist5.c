#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// 定义结构体
typedef struct LinkList{
    int data;
    struct LinkList * next;
} link;

// 初始化链表
link * InitLinkList(){
    link * node = (link *) malloc(sizeof(link));
    node->next = NULL;
    return node;
}

// 添加数据
void addLinkList(link * p){
    link * work = p;

    for(int i=1;i<10;i++){
        // 创建新元素
        link * tmp = (link *) malloc(sizeof(link));
        tmp ->data = i;
        tmp ->next = NULL;

        // 链域关联
        work ->next = tmp;
        work = tmp;
    }
}

// 链表数据展示
void input(link * p){
    link * tmp = p;
    while(tmp){
        printf("%d  ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

// 求表长
int GetLinkListLenght(link * p){
    link * tmp = p;
    int i = 0;
    while(tmp->next != NULL){
        tmp = tmp->next;
        i++;
    }
    return i;
}

// 读表
link * GetLinkList(link * p,int i){
    link * tmp = p;
    int j = 0;
    while(j<=i){
        if(j==i){
            return tmp;
        }
        j++;
        tmp = tmp->next;
    }
}

// 插入
void InsertLinkList(link *p,int num,int pos){
    link * prev = GetLinkList(p,pos-1);
    link * insert = (link *) malloc(sizeof(link));
    insert->data = num;
    insert-> next = prev->next;
    prev->next = insert;
}

// 删除
void DeleteLinkList(link *p,int pos){
    link * prev = GetLinkList(p,pos-1);
    link * del = prev->next;
    prev->next = del->next;
    free(del);
}

int main(void){

    //初始化链表
    link * p = InitLinkList();

    // 添加数据
    addLinkList(p);
    printf("链表初始化为：");
    input(p);

    // 求表长
    int lenght = GetLinkListLenght(p);
    printf("链表长度为：%d\n",lenght);

    // 读表
    link * select = GetLinkList(p,4);
    printf("链表地址为：%p\n",select);

    // 插入
    InsertLinkList(p,19,7);
    printf("插入后链接数据为：");
    input(p);

    // 删除
    DeleteLinkList(p,5);
    printf("删除后链接数据为：");
    input(p);

    return 0;
}