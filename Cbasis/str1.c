#include <stdio.h>

int main(void){
	// 
	struct array {
		int a;      // 成员
		char b[2];
		int c;
		char d[4];
	};

	typedef struct array a;
       	
	a a1 = {10,"B",20,"DD"};

	printf("a1中 a=%d,b=%s,c=%d,d=%s\n",a1.a,a1.b,a1.c,a1.d);	
}
