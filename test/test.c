#include <stdio.h>
#include <stdlib.h>

int main(void){
    // 九九乘法表
    for(int i=1;i<=9;i++){
        for(int j=1;j<=i;j++){
            printf("%dX%d=%d ",i,j,i*j);
        }
        printf("\n");
    }
}