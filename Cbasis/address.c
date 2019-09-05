#include <stdio.h>

int main(){
    // 声明变量a,值为2
    int a = 2;
    printf("a的值为：%d\n",a);

    // 声明变量b,值为a的地址
    int * b = &a;
    printf("a的地址为：%p\n",b);
    printf("b的值为：%d\n",*b);
    
    // 通过指针修改a的值
    *b =5;
    printf("b的值为：%d\n",*b);
    return 0;
}
