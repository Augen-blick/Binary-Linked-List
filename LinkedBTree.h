#pragma once
#include <iostream>
#define MaxSize 30
using namespace std;

typedef char ElemType;
typedef struct node
{
	ElemType data;						//����Ԫ��
	struct node* lchild;			//ָ�����ӽ��
	struct node* rchild;			//ָ���Һ��ӽ��
} BTNode;

void CreateBTree(BTNode*& b, char* str);			//����������
void DestroyBTree(BTNode*& b);						//���ٶ�����
BTNode* FindNode(BTNode* b, ElemType x);			//���ҽ��
BTNode* LchildNode(BTNode* p);						//����p����ָ��
BTNode* RchildNode(BTNode* p);						//����p�Һ���ָ��
int BTHeight(BTNode* b);							//�����ĸ߶�
void DispBTree(BTNode* b);							//���������

void CreateBTree(BTNode*& b, char* str)				//����������
{
	BTNode* St[MaxSize] = { NULL }, * p = NULL;	//St������Ϊ˳��ջ
	int top = -1, j = 0, k;					//top��Ϊջ��ָ�룬k��ʾ�Ǵ������ӻ����Һ���
	char ch = str[j];
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':								//��ʼ�������ӽ��
			top++; St[top] = p; k = 1; break;	//p��ջ��k=1��ʾ�Ǵ������ӽ��
		case ')':
			top--; break;						//ջ����������������ϣ���ջ
		case ',':
			k = 2; break;						//k=2��ʾ��ʼ�����Һ��ӽ��
		default:								//��Ϊ����ʱ
			p = (BTNode*)malloc(sizeof(BTNode));//����һ���½�㣬��pָ����
			p->data = ch;						//��ֵ
			p->lchild = p->rchild = NULL;		//�����Ӹ�ֵNULL
			if (b == NULL)						//��bΪ��ʱ��Ϊ�����
				b = p;
			else								//���Ǹ����ʱ
			{
				switch (k)
				{
				case 1:
					St[top]->lchild = p; break;	//k=1��pΪջ��������
				case 2:
					St[top]->rchild = p; break;	//k=2��pΪջ�����Һ���
				}
			}
		}
		ch = str[++j];							//����ɨ��str
	}
}

void DestroyBTree(BTNode*& b)						//���ٶ�����
{
	if (b != NULL)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}

BTNode* FindNode(BTNode* b, ElemType x)				//���ҽ��
{
	BTNode* p;
	if (b == NULL)
		return NULL;
	else if (b->data == x)
		return b;
	else
	{
		p = FindNode(b->lchild, x);
		if (p != NULL)
			return p;
		else
			return FindNode(b->rchild, x);
	}
}

BTNode* LchildNode(BTNode* p)						//����p����ָ��
{
	return p->lchild;
}

BTNode* RchildNode(BTNode* p)						//����p�Һ���ָ��
{
	return p->rchild;
}

int BTHeight(BTNode* b)								//�����ĸ߶�
{
	int lchildh, rchildh;
	if (b == NULL)
		return 0;
	else
	{
		lchildh = BTHeight(b->lchild);				//�������߶�Ϊlchild
		rchildh = BTHeight(b->rchild);				//�������߶�Ϊrchlid
		return (rchildh > lchildh) ? (rchildh + 1) : (lchildh + 1);
	}
}

void DispBTree(BTNode* b)							//���������
{
	if (b != NULL)
	{
		cout << b->data;
		if (b->lchild != NULL || b->rchild != NULL)
		{
			cout << "(";						//�к��ӽ�����")"
			DispBTree(b->lchild);				//�ݹ鴦��������
			if (b->rchild != NULL)
				cout << ",";					//���Һ��Ӳ����","
			DispBTree(b->rchild);				//�ݹ鴦���Һ���
			cout << ")";						//����������")"
		}
	}
}