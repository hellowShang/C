#include <stdio.h>

int main(void){
    int a = 1;
    int b = 2;

    printf("初始值：a=%d,b=%d\n",a,b);

    void f(int *x,int *y){
        int tmp = *x;
        *x = *y;
        *y = tmp;
    }

    f(&a,&b);
    printf("取地址运算后：a=%d,b=%d\n",a,b);
}


//insertseqlist(seq *L,D x,int i){
//    for(int j=L->lenght;j>=i;j--){
//        L->data[j] = L->data[j-1];
//    }
//        L->data[i-1] = x;
//        L->data++;
//}
//
//deleteseqlist(seq *L,int i){
//    for(int j=i;j<=L->lenght;j++){
//        L->data[j-1] = L->data[j];
//    }
//
//    L->data--;
//}