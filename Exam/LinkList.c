#include <stdio.h>
#include <stdlib.h>

typedef struct LinkList{
    int data;
    struct LinkList * next;
}LL;

// 初始化
LL * InitList(){
    LL * tmp = (LL *) malloc(sizeof(LL));
    tmp->next = NULL;
    return tmp;
}

// 添加数据
void AddList(LL * head){
    LL * p = head;
    for(int i =1;i<=8;i++){
        LL * tmp = (LL *) malloc(sizeof(LL));
        tmp->data = i;
        tmp->next = NULL;

        // 关联
        p-> next = tmp;
        p=tmp;
    }
}

// 求表长
int LenghtList(LL * head){
    LL * p = head;
    int num = 0;
    while(p->next != NULL){
        num++;
        p=p->next;
    }
    return num;
}

// 读表数据
int ReadList(LL * head,int i){
    LL * p = head;
    int j=0;
    while(j<=i){
        if(j == i){
            return p->data;
        }
        j++;
        p=p->next;
    }
}

// 定位
LL * LocaList(LL * head,int i){
     LL * p = head;
        int j=0;
        while(j<=i){
            if(j == i){
                return p;
            }
            j++;
            p=p->next;
        }
}

// 插入
void InsertList(LL * head,int num,int i){
    LL * prev =LocaList(head,i-1);
    LL * insert = (LL *)malloc(sizeof(LL));
    insert->data = num;
    insert->next = prev->next;
    prev->next = insert;
}

// 删除
void DeleteList(LL * head,int i){
    LL * prev =LocaList(head,i-1);
    LL * p = prev->next;
    prev->next = p->next;
    free(p);
}

// 输出
void input(LL * head){
    LL * p = head->next;
    while(p){
        printf("data：%d\n",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(void){
    // 初始化
    LL * head = InitList();

    // 添加数据
    AddList(head);
    // 输出
    printf("添加数据后为：\n");
    input(head);

    // 求表长
    int lenght = LenghtList(head);
    printf("表长为：%d\n",lenght);
    printf("\n");

    // 读表元素
    int data = ReadList(head,5);
    printf("data：%d\n",data);
    printf("\n");

    // 定位
    LL * location = LocaList(head,5);
    printf("location：%p\n",location);
    printf("\n");

    // 插入
    InsertList(head,90,3);
    input(head);

    // 删除
    DeleteList(head,5);
    input(head);

    return 0;
}