#pragma once
#include <iostream>
#define MaxSize 30
using namespace std;

typedef char ElemType;
typedef struct node
{
	ElemType data;						//数据元素
	struct node* lchild;			//指向左孩子结点
	struct node* rchild;			//指向右孩子结点
} BTNode;

void CreateBTree(BTNode*& b, char* str);			//创建二叉树
void DestroyBTree(BTNode*& b);						//销毁二叉树
BTNode* FindNode(BTNode* b, ElemType x);			//查找结点
BTNode* LchildNode(BTNode* p);						//返回p左孩子指针
BTNode* RchildNode(BTNode* p);						//返回p右孩子指针
int BTHeight(BTNode* b);							//求树的高度
void DispBTree(BTNode* b);							//输出二叉树

void CreateBTree(BTNode*& b, char* str)				//创建二叉树
{
	BTNode* St[MaxSize] = { NULL }, * p = NULL;	//St数组作为顺序栈
	int top = -1, j = 0, k;					//top作为栈顶指针，k表示是处理左孩子还是右孩子
	char ch = str[j];
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':								//开始处理左孩子结点
			top++; St[top] = p; k = 1; break;	//p进栈，k=1表示是处理左孩子结点
		case ')':
			top--; break;						//栈顶结点的子树处理完毕，出栈
		case ',':
			k = 2; break;						//k=2表示开始处理右孩子结点
		default:								//当为数据时
			p = (BTNode*)malloc(sizeof(BTNode));//创建一个新结点，用p指向它
			p->data = ch;						//赋值
			p->lchild = p->rchild = NULL;		//将孩子赋值NULL
			if (b == NULL)						//当b为空时，为根结点
				b = p;
			else								//不是根结点时
			{
				switch (k)
				{
				case 1:
					St[top]->lchild = p; break;	//k=1，p为栈顶的左孩子
				case 2:
					St[top]->rchild = p; break;	//k=2，p为栈顶的右孩子
				}
			}
		}
		ch = str[++j];							//继续扫描str
	}
}

void DestroyBTree(BTNode*& b)						//销毁二叉树
{
	if (b != NULL)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}

BTNode* FindNode(BTNode* b, ElemType x)				//查找结点
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

BTNode* LchildNode(BTNode* p)						//返回p左孩子指针
{
	return p->lchild;
}

BTNode* RchildNode(BTNode* p)						//返回p右孩子指针
{
	return p->rchild;
}

int BTHeight(BTNode* b)								//求树的高度
{
	int lchildh, rchildh;
	if (b == NULL)
		return 0;
	else
	{
		lchildh = BTHeight(b->lchild);				//左子树高度为lchild
		rchildh = BTHeight(b->rchild);				//右子树高度为rchlid
		return (rchildh > lchildh) ? (rchildh + 1) : (lchildh + 1);
	}
}

void DispBTree(BTNode* b)							//输出二叉树
{
	if (b != NULL)
	{
		cout << b->data;
		if (b->lchild != NULL || b->rchild != NULL)
		{
			cout << "(";						//有孩子结点输出")"
			DispBTree(b->lchild);				//递归处理左子树
			if (b->rchild != NULL)
				cout << ",";					//有右孩子才输出","
			DispBTree(b->rchild);				//递归处理右孩子
			cout << ")";						//处理完毕输出")"
		}
	}
}