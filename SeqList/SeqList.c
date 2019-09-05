#include <stdio.h>

// 定义一个变量为表的最大长度
    int Maxsize = 8;

// 1.定义一个 dataType结构体 别名为D
struct dataType {
    int age;
    char name[64];
    char sex;
    int num;
};

typedef struct dataType D;

// 2.定义一个 顺序表 别名seq
struct SeqList{
    D data[8];
    int lenght;
};

typedef struct SeqList Seq;

int main(void){

    // 定义顺序表变量 student并插入数据
	Seq Student = {{
	    {11,"yuweiwen",'F',1},
	    {12,"tuoersuo",'M',2},
	    {13,"xiaoxuesheng",'M',3},
	    {14,"tikuanji",'F',4},
	    {15,"xizhilang",'M',5},
	},5};

    // 插入数据输出查看
    for(int i=0;i<Maxsize;i++){
        printf("Student%d的age：%d，name：%s，sex：%c，num：%d\n",i,Student.data[i].age,Student.data[i].name,Student.data[i].sex,Student.data[i].num);
    }
    printf("表长：%d\n",Student.lenght);


/**                        分            割              区              */
printf("***********************分割区******************************\n");


	// 定义插入运算函数   将元素x插入到顺序表student的第i个元素之前
	void InsertSeqList(Seq *L,D x,int i){
		if(L->lenght == Maxsize){
			printf("表已经满了\n");
		}
		if(i<1 || i>L->lenght+1){
		    printf("位置错误\n");
		}

        // 移动元素位置
		for(int j=L->lenght;j>=i;j--){
			L->data[j] = L->data[j-1];    // 依次后移
		}

		// 新元素插入到下标为i-1位置
        L->data[i-1] = x;

        // 表长+1
        L->lenght++;
	}

    // 定义新元素x  调用插入函数 插入位置为3
    D x = {50,"wawayu",'F',10};
    InsertSeqList(&Student,x,3);

    // 插入元素后输出
    for(int i=0;i<=Maxsize;i++){
        printf("Student%d的age：%d，name：%s，sex：%c，num：%d\n",i,Student.data[i].age,Student.data[i].name,Student.data[i].sex,Student.data[i].num);
    }
    printf("表长为：%d\n",Student.lenght);


/**                        分            割              区              */
printf("***********************分割区******************************\n");


    // 删除元素运算函数  删除线性表中的第i个元素
    void DeleteSeqList(Seq *L,int i){
        if(i<1 || i>L->lenght+1){
            printf("位置错误\n");
        }

        // 第i个元素的下标为i-1
        for(int j=i;j<=L->lenght;j++){
            L->data[j-1] = L->data[j];  // 依次左移
        }

        // 表长度-1
        L->lenght--;
    }

    // 调用删除函数  删除的元素为2
    DeleteSeqList(&Student,2);

    // 删除元素后输出
    for(int i=0;i<=Maxsize;i++){
        printf("Student%d的age：%d，name：%s，sex：%c，num：%d\n",i,Student.data[i].age,Student.data[i].name,Student.data[i].sex,Student.data[i].num);
    }
    printf("表长为：%d\n",Student.lenght);


/**                        分            割              区              */
printf("***********************分割区******************************\n");


    // 定义定位运算函数  查找线性表


    return 0;
}
