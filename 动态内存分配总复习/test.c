#include <stdio.h>

//�������鸴ϰ

struct S
{
	int a;
	int arr[0];   //���������Ա����ĩβ��ǰ�����ٵ���һ����Ա
	// int arr[];  //���ַ�ʽ������
};

int main()
{
	struct S* p=(struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));  //�����������ռ�
	//���ṹ���һ��Ԫ�ظ�ֵ
	p->a = 100;
	//���ṹ���еڶ���Ԫ�أ����飩��ֵ
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		p->arr[i] = i;
	}
	//��ӡ������
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p->arr[i]);
	}
	//�ͷ��ڴ� - ��ֹ�ڴ�й©
	free(p);
	p = NULL;

	return 0;
}


//��һ��ʹ�ṹ����ĳ�����С�ɶ�̬����

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
	//�����ͷ��ڴ�ʱҪ����ע��
	//���ͷ�arrָ��ĵ�ַ�����ͷ�p����������Ϊ�˷�ֹ�����ͷ�p�����Ҳ���arrָ��ĵ�ַ��
	free(p->arr);
	p->arr = NULL;
	free(p);
	p = NULL;
	return 0;
}