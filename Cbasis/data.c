#include <stdio.h>

int main(){
   // 定义一个数组和长度
   int arr[5];
   int arr2[10];
   for(int i=0;i<5;i++){
        arr[i] = i + 10;
	printf("arr的第%d个元素，值为%d\n",i,arr[i]);
	printf("arr的第%d个元素的地址为%p\n",i,&arr[i]);
   }

   printf("\n");

   for(int a=0;a<10;a++){
	arr[a] = a * 4;
	printf("arr的第%d个元素，值为%d\n",a,arr[a]);
	printf("arr的第%d个元素的地址为%p\n",a,&arr[a]);
   }
   return 0;
}
