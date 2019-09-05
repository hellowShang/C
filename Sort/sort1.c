#include <stdio.h>
#include <stdlib.h>

// 定义数组长度
#define MAX 10

// 定义结构体
typedef struct RecodeSort{
    int key;            // 排序键值 可以根据业务需求添加别的字段
}R;
typedef R arr[MAX+1];

// 冒泡排序
void bubbblingSort(arr R,int n){
    int i,j,end;
    for(i=1;i<n-1;i++){
        end = 0;
        for(j=1;j<=n-i;j++){
            if(R[j].key >R[j+1].key){
                R[0] = R[j];
                R[j] = R[j+1];
                R[j+1] = R[0];
                end=1;
            }
        }
        if(end == 0){
            break;
        }
    }
}

int main(void){

    R arr[MAX+1];
    printf("数据添加到数组：");
    // 添加数据到数组
    for(int i=1;i<=MAX;i++){
        int num = rand() % 100;
        printf("%d,",num);
        arr[i].key = num;
    }
    printf("\n");

    // 冒泡排序
    bubbblingSort(arr,MAX);

    // 数据查看
    printf("冒泡排序后查看：");
    for(int i=1;i<=MAX;i++){
        printf("%d,",arr[i].key);
    }
    printf("\n");

}