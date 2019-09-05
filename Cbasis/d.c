#include <stdio.h>

int main(void){
	int a =1;
	int b =2;
	int *c = &a;     // 定义一个变量c 他的类型是int *  值为变量a的地址
	int *d = &b;     // 定义一个变量d 他的类型是int *  值为变量b的地址

	printf("初始值：a=%d,b=%d,c=%p,d=%p\n",a,b,c,d);	

	void f(int *x,int *y){
		int t = *x;  // 找到x变量保存的地址所指向的变量  此时*号为地址运算符
		*x = *y;   // * x <==> a   *y <==> b
		*y = t;
	}
	

	f(&a,&b);
	printf("地址运算后：a=%d,b=%d\n",a,b);
	return 0;
}
