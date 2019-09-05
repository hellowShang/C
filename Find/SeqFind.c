#include <stdio.h>
#include <stdlib.h>

#define MAX 6
typedef struct TableElem{
    int key;
    int age;
}table;

typedef struct SeqTable{
    table elem[MAX+1];
    int n;
}ST;

// 顺序查找
int  FindSeq(ST  * p,int key){
    int i = p->n;
    p->elem[0].key = key;
    while(p->elem[i].key != key){
        i--;
    }
    return i;
}

// 二分查找(折半查找)
int Find(ST * p,int key){
    // 查找初值
    int front,rear,mid;
    front = 1;
    rear = p->n;
    while(front <= rear){
        mid = (front+rear)/2;
//        printf("mid:%d\n",mid);
//        printf("front:%d\n",front);
//        printf("rear:%d\n",rear);
        if(p->elem[mid].key == key){
            return mid;
        }else if(key > p->elem[mid].key){
            front = mid+1;
        }else{
            rear = mid-1;
        }
    }
    return 0;                                   // 查找不成功，返回0
}


int main(void){
    ST st;
    ST * p = &st;

    // 输入添加数据
    int i = 1;
    while(i<=MAX){
        int m;
        printf("请输入第%d个key，共%d个key\n",i,MAX);
        scanf("%d",&m);
        getchar();
        p->elem[i].key = m;

        int n;
        printf("请输入第%d个age，共%d个age\n",i,MAX);
        scanf("%d",&n);
        getchar();
        p->elem[i].age = n;
        p->n = i;       // 加表长
        i++;
    }

    // 输出查看
    int j = 1;
    while(j<=MAX){
        printf("第%d个元素的key：%d，age:%d\n",j,p->elem[j].key,p->elem[j].age);
        j++;
    }

//    // 顺序查找
//    int t;
//    printf("请输入查找的key：");
//    scanf("%d",&t);
//    getchar();
//    int pos = FindSeq(p,t);
//    printf("查找的元素为的key为：%d，age为：%d，\n",p->elem[pos].key,p->elem[pos].age);

    // 二分查找
    int t1;
    printf("请输入查找的key：");
    scanf("%d",&t1);
    getchar();
    int pos1 = Find(p,t1);
    printf("查找的元素为的key为：%d，age为：%d，\n",p->elem[pos1].key,p->elem[pos1].age);
}
