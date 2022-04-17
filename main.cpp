#include "LinkedBTree.h"

int main()
{
	//存储二叉树的数组
	char str[30];
	
	cout << "请输入一个二叉树(括号表示法)" << endl;
	cin >> str;

	//定义链二叉树
	BTNode* b = NULL;

	//创建二叉树
	CreateBTree(b, str);

	//输出
	cout << "该二叉树为：";
	DispBTree(b);
	cout << endl;

	//求树的高度
	cout << "该树的高度为：" << BTHeight(b) << endl;

	//求值为x的节点
	BTNode* p = FindNode(b, 'D');

	//求左右孩子结点
	cout << "D的左孩子结点为：";
	if (LchildNode(p) == NULL)
		cout << "NULL" << endl;
	else
		cout << LchildNode(p)->data << endl;
	cout << "D的右孩子结点为：";
	if (RchildNode(p) == NULL)
		cout << "NULL" << endl;
	else
		cout << RchildNode(p)->data << endl;

	//销毁二叉树
	DestroyBTree(b);
}