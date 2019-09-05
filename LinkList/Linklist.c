#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(void){

    // 定义一个 dateType的结构体 别名D
    typedef struct dateType {
        int age;
        char name[64];
        char sex;
        char email[64];
    } D;

    // 定义一个链表  别名N
    typedef struct node{
        D data;                         // 数据域
        struct node * next;             // 指针域
    } N;

    // 定义首个元素节点
    N * first = (N *) malloc(sizeof(N));                    // 分配内存(内存是计算出来的)
    D x = {10,"lisi",'M',"lisi1111@qq.com"};
    first ->data = x;                                        // 数据域赋值
    first ->next = NULL;                                    // 指针域暂未知  赋值NULL
    N * head = first;                                       // 头结点   指向   首节点

    N * second = (N *) malloc(sizeof(N));
    D x1 = {11,"lisi1",'F',"lisi222222@qq.com"};
    second -> data = x1;
    second -> next = NULL;
    first -> next = second;

    // 展示数据
    while(head){
        printf("N的age：%d，name：%s，sex：%c，email：%s\n",head->data.age,head->data.name,head->data.sex,head->data.email);
        head = head->next;
    }

    return 0;
}