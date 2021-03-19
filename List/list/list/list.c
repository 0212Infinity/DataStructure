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

//����Ԫ�� �ڵ�n��λ�ò���Ԫ��x
Status insertList(SqList* list, int n, ElemType x) {
	int i;
	//list�Ƿ���
	if (list->length == MAXSIZE) {
		return ERROR;
	}
	//�����n�Ƿ�Ϸ�
	if (n<1 || n>list->length + 1) {
		return ERROR;
	}
	//�����Ƿ��Ǳ�β
	if (n <= list->length) {
		//�ѵ�i��λ�ú�ȫ������
		for (i = list->length - 1; i >= n - 1; i--) {
			list->elem[i + 1] = list->elem[i];
		}
	}
	list->elem[n - 1] = x;
	list->length++;

	return OK;
}

//��ʼ��
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

//ɾ����n��λ�õ�Ԫ�� �浽x��
Status deleList(SqList* list, int n, ElemType* x) {
	int i;
	//�Ƿ��ǿձ�
	if (list->length == 0) {
		return ERROR;
	}
	//�ж��Ƿ�Խ��
	if (n < 1 || n > list->length) {
		return ERROR;
	}
	*x = list->elem[n - 1];
	if (n < list->length) {
		//����������һ��Ԫ��
		for (i = n; i < list->length; i++) {
			list->elem[i - 1] = list->elem[i];
		}
	}
	list->length--;
	return OK;
}

//��ȡ��n��λ�õ�Ԫ�� �浽x��
Status getElem(SqList* list, int n, ElemType* x) {
	//�ж�һ��
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

//����
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
		printf("��ȡ����Ԫ��Ϊ: %d\n", i);
	}
	//����s2
	initList(&s2);
	insertList(&s2, 1, 111);
	insertList(&s2, 2, 222);
	insertList(&s2, 3, 11);
	//����
	unionList(&s1, &s2);
	printList(&s1);
	return 0;
}
