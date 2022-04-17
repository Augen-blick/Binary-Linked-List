#include "LinkedBTree.h"

int main()
{
	//�洢������������
	char str[30];
	
	cout << "������һ��������(���ű�ʾ��)" << endl;
	cin >> str;

	//������������
	BTNode* b = NULL;

	//����������
	CreateBTree(b, str);

	//���
	cout << "�ö�����Ϊ��";
	DispBTree(b);
	cout << endl;

	//�����ĸ߶�
	cout << "�����ĸ߶�Ϊ��" << BTHeight(b) << endl;

	//��ֵΪx�Ľڵ�
	BTNode* p = FindNode(b, 'D');

	//�����Һ��ӽ��
	cout << "D�����ӽ��Ϊ��";
	if (LchildNode(p) == NULL)
		cout << "NULL" << endl;
	else
		cout << LchildNode(p)->data << endl;
	cout << "D���Һ��ӽ��Ϊ��";
	if (RchildNode(p) == NULL)
		cout << "NULL" << endl;
	else
		cout << RchildNode(p)->data << endl;

	//���ٶ�����
	DestroyBTree(b);
}