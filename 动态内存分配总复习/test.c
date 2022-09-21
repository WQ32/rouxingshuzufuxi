#include <stdio.h>

//柔性数组复习

struct S
{
	int a;
	int arr[0];   //柔性数组成员，在末尾，前面至少得有一个成员
	// int arr[];  //两种方式都可以
};

int main()
{
	struct S* p=(struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));  //开辟两连续空间
	//给结构体第一个元素赋值
	p->a = 100;
	//给结构体中第二个元素（数组）赋值
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		p->arr[i] = i;
	}
	//打印数组结果
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p->arr[i]);
	}
	//释放内存 - 防止内存泄漏
	free(p);
	p = NULL;

	return 0;
}


//另一种使结构体中某数组大小可动态分配

struct S
{
	int a;
	int* arr;
};

int main()
{
	struct S* p = (struct S*)malloc(sizeof(struct S));
	p->a = 100;
	p->arr = malloc(10 * sizeof(int));
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		p->arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p->arr[i]);
	}
	//这里释放内存时要尤其注意
	//先释放arr指向的地址，在释放p，这样做是为了防止，先释放p，就找不到arr指向的地址了
	free(p->arr);
	p->arr = NULL;
	free(p);
	p = NULL;
	return 0;
}