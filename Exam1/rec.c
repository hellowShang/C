#include <stdio.h>
#include <stdlib.h>

// 斐波那契
long f(int n){
    if(n<=2){
        return 1;
    }else{
        return f(n-1)+f(n-2);
    }
}

// 求介乘
long m(int n){
    if(n<=1){
        return 1;
    }else{
        return m(n-1)*n;
    }
}

int main(void){
   // 斐波那契
   long e = f(10);
   printf("斐波那契10值为：%ld\n",e);
   // 求介乘
   long r = m(10);
   printf("介乘10值为：%ld\n",r);
}