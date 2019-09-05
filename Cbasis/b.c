#include <stdio.h>
int main(){
    // 输出int类型所占的字节
    printf("Int size:%lu\n",sizeof(int));

    // 变量声明
    int a = 3;
    int b = 4;

    // 逻辑处理
    int c = a + b;

    // 输出a+b=c
    printf("a+b=%d\n",c);

    // 返回结果
    return 0;
}
