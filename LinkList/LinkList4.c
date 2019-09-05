#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// 定义结构体
typedef struct LinkList{
    int num;                        // 数据域
    struct LinkList * next;         // 指针域
}LL;

// 初始化链表
LL * IninLinkList(){
    LL * node = (LL *) malloc(sizeof(LL));     // 分配内存
    node-> next = NULL;                        // 指针域指向暂未知为空
    return node;
};

// 链表数据添加
void addLinkList(LL * head){
    LL * p = head;                  // 以下的p均为工作指针

    // 循环创建元素并插入数据
    for(int i=1;i<10;i++){
        // 创建元素
        LL * tmp = (LL *) malloc(sizeof(LL));       // 分配内存
        tmp -> num =i;                              // 数据域添加数据
        tmp -> next = NULL;                         // 指针域指向暂未知为空

        // 关联元素
        p-> next = tmp;                             // 指针域指向下一个结点的首地址
        p= tmp;
    };
}

// 展示链表数据
void input(LL * head){
    LL * p = head;
    while(p){
        printf("%d  ",p->num);
        p = p->next;
    };
    printf("\n");
}

// 求表长
int LenghtLinkList(LL * head){
    LL * p = head;
    int cnt = 0;
    // 判断是否为尾结点
    while(p->next != NULL){
        p = p->next;
        cnt++;
    }
    return cnt;
}

// 链表中查找某结点(读表元素)  head为链表  i为查找的元素
LL * selectElem(LL * head,int i){
    LL *p = head;
    int j=0;
    while (j <= i) {
        if (j==i) {
        // printf("j:%d\n",j);
            return p;       // 返回查找元素的地址
        }
        p=p->next;
        j++;
    }
}

// 插入
void InsertLinkList(LL * head,int num,int i){
    LL * prev = selectElem(head,i-1);               // 返回上一个元素的地址
    if(prev == NULL){
        printf("找不到插入的位置");
    }else{
        LL * insert = (LL *) malloc(sizeof(LL));    // 分配内存地址
        insert ->num = num;                         // 新元素赋值
        insert ->next = prev ->next;                // 新结点的指针域的地址 = 插入之前的q的指向域
        prev ->next = insert;                       // 插入之前的q的指向域的地址  =  插入的新元素的地址
    }
}

// 删除
void DeleteLinkList(LL * head,int i){
        LL * prev = selectElem(head,i-1);       // 返回上一个元素的地址
    if( prev != NULL){
        LL * delnode =prev->next;               // 保存删除结点的地址
        prev ->next = delnode ->next;           // 要删除结点的直接前驱的指向域指向要删除结点的直接后继的首地址
        free(delnode);                          // 释放内存
    }else{
        printf("找不到要删除的结点\n");
    }
}

int main(void){
    // 初始化链表
    LL * head = IninLinkList();     // 保存初始化链表的地址

    addLinkList(head);
    // 链表数据输出
    printf("链表数据为：");
    input(head);

    // 求表长
    int lenght = LenghtLinkList(head);
    printf("链表表长为：%d\n",lenght);

    // 读表元素
    LL * select = selectElem(head,3);
    printf("表元素的地址为：%p\n",select);

    // 插入
    InsertLinkList(head,15,4);
    printf("插入后后链表数据为：");
    input(head);

    // 删除
    DeleteLinkList(head,5);
    printf("删除后链表数据为：");
    input(head);


    return 0;
}