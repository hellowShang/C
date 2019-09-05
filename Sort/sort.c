#include <stdio.h>
#include <stdlib.h>

// 定义数组长度
#define MAX 10

// 定义结构
typedef struct{
    int key;        // 排序键值
    // 添加业务需求
}SortType;
typedef SortType arr[MAX+1];     // 定义arr为SortType类型数组

// 直接插入排序
void InsertSort(arr m,int n){                   // 对顺序表为m进行直接插入排序
    int i,j;
    for(i=2;i<=n;i++){                          // n为表长，从第二个记录去进行插入
        j=i-1;
        m[0] = m[i];                            // 第i个记录赋值给岗哨

        while(m[0].key < m[j].key){             // 与岗哨比较，直至键值不大于岗哨键值
            m[j+1] = m[j];                      // 将第j个记录赋值为第j+1个记录
            j--;
        }

        m[j+1] = m[0];                          // 将第i个记录插入到序列中
    }
}

int main(void){
    // 待排序列
    SortType arr[MAX+1];

    // 初始化
    printf("初始化数据为：");
    for(int n=1;n<=MAX;n++){
        int num = rand() % 100;
        printf("%d,",num);
        arr[n].key = num;
    }
    printf("\n");

    // 数据查看
    printf("数据查看：");
    for(int i=1;i<=MAX;i++){
        printf("%d，",arr[i].key);
    }
    printf("\n");

    // 直接插入排序
    InsertSort(arr,MAX);

    // 数据查看
        printf("排序后数据查看：");
        for(int i=1;i<=MAX;i++){
            printf("%d，",arr[i].key);
        }
        printf("\n");

}