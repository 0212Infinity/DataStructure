#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;

typedef struct {
	ElemType elem[MAXSIZE];
	int length;
}SqList;

//插入元素 在第n个位置插入元素x
Status insertList(SqList* list, int n, ElemType x) {
	int i;
	//list是否满
	if (list->length == MAXSIZE) {
		return ERROR;
	}
	//输入的n是否合法
	if (n<1 || n>list->length + 1) {
		return ERROR;
	}
	//插入是否是表尾
	if (n <= list->length) {
		//把第i个位置后全部后移
		for (i = list->length - 1; i >= n - 1; i--) {
			list->elem[i + 1] = list->elem[i];
		}
	}
	list->elem[n - 1] = x;
	list->length++;

	return OK;
}

//初始化
Status initList(SqList* list) {
	list->length = 0;
	return OK;
}

Status printList(SqList* list) {
	int i;
	for (i = 0; i < list->length; i++) {
		printf("%d ", list->elem[i]);
	}
	printf("\n");
	return OK;
}

//删除第n个位置的元素 存到x中
Status deleList(SqList* list, int n, ElemType* x) {
	int i;
	//是否是空表
	if (list->length == 0) {
		return ERROR;
	}
	//判断是否越界
	if (n < 1 || n > list->length) {
		return ERROR;
	}
	*x = list->elem[n - 1];
	if (n < list->length) {
		//如果不是最后一个元素
		for (i = n; i < list->length; i++) {
			list->elem[i - 1] = list->elem[i];
		}
	}
	list->length--;
	return OK;
}

//获取第n个位置的元素 存到x中
Status getElem(SqList* list, int n, ElemType* x) {
	//判断一下
	if (list->length == 0 || n < 1 || n > list->length) {
		return ERROR;
	}
	*x = list->elem[n - 1];
	return OK;
}

Status locateElem(SqList* list, ElemType e) {
	int i;
	for (i = 0; i < list->length; i++) {
		if (list->elem[i] == e) {
			return OK;
		}
	}
	return ERROR;
}

//并集
void unionList(SqList* list1, SqList* list2) {
	int i;
	ElemType e;
	for (i = 0; i < list2->length; i++) {
		e = list2->elem[i];
		if (!locateElem(list1, e)) {
			insertList(list1, list1->length + 1, e);
		}
	}
}

int main() {
	SqList s1, s2;
	int i;
	int status;
	initList(&s1);
	insertList(&s1, 1, 1);
	printList(&s1);
	insertList(&s1, 1, 11);
	printList(&s1);
	deleList(&s1, 2, &i);
	printList(&s1);
	status = getElem(&s1, 1, &i);
	if (status) {
		printf("获取到的元素为: %d\n", i);
	}
	//创建s2
	initList(&s2);
	insertList(&s2, 1, 111);
	insertList(&s2, 2, 222);
	insertList(&s2, 3, 11);
	//并集
	unionList(&s1, &s2);
	printList(&s1);
	return 0;
}
