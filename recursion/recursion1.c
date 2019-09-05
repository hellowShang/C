#include <stdio.h>

// 斐波那契数列    公式n=(n-1)+(n-2)
long f(int n){
    if(n<=2){
        return 1;
    }else{
       return f(n-1)+f(n-2);
    }
}

// 求介乘          公式n=n*(n-1)
long m(int n){
    if(n<=1){
        return 1;
    }else{
        return m(n-1)*n;
    }
}

// 倒序

int main(void){
    printf("斐波那契数列第10个，值为：");
    long num = f(10);
    printf("%ld\n",num);

    printf("介乘第4个，值为：");
    long num1 = m(4);
    printf("%ld\n",num1);


}