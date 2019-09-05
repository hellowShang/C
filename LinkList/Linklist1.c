#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// 定义一个链表  别名N
typedef struct node{
    int num;
    struct node * next;
} N;

// 初始化单链表   **L为计算地址的地址
void initList(N **L){
    *L = (N *) malloc(sizeof(N));
    (*L)->next = NULL;
};

int main(void){
    N * la;
    N * temp;
    N * head;
    initList(&la);

    head = la;
    for(int i=1;i<11;i++){
        temp = (N *) malloc(sizeof(N));
        temp->num  = i*100;
        temp->next = NULL;
        head->next = temp;
        head = head->next;
    }
    head= la->next;
     // 展示数据
    while(head){
        printf("num:%d\n",head->num);
        head = head->next;
    };

    return 0;
}
