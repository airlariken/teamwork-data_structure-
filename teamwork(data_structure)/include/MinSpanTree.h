#ifndef MinSpanTree_h
#define MinSpanTree_h
#include <iostream>

struct TreeNode
{
	bool existence = false;
	int weight = 0;
	int postion = 0;
	int nextpos = 0;
	TreeNode* Link = NULL;
	TreeNode()
	{

	}
	~TreeNode()
	{

	}
};

class MinSpanTree
{
public:
	int RealNodeCount = 0;  //�ó�Ա����������������ǰֹͣKruskal�㷨
	TreeNode* nodes = NULL;
	MinSpanTree(int verCount)
	{
		nodes = new TreeNode[verCount];
	}
	~MinSpanTree()
	{

	}
	bool MSTinseart(int Position, int NextPos, int Weight) //�ú���Ϊbool�ͣ�����ǰ���ж��Ƿ�ɻ����ɻ��򷵻�false�����ɻ���������в�����true
	{
		if (nodes[Position].existence && nodes[NextPos].existence)
			return false;    //�ж��Ƿ�ɻ������ɻ��򷵻�false
		else
		{
			//���ɻ��������
			TreeNode* newnode1 = new TreeNode();   //newһ���½��
			newnode1->nextpos = NextPos;    //��ֵ��Ӧ�ı���
			newnode1->weight = Weight;
			//�����һ�����
			if (nodes[Position].Link == NULL)nodes[Position].Link = newnode1;
			else
			{
				TreeNode* node = nodes[Position].Link;
				while (node->Link)node = node->Link;
				node->Link = newnode1;
			}

			TreeNode* newnode2 = new TreeNode();  //new�ڶ����½��
			newnode2->nextpos = Position;    //��ֵ��Ӧ�ı���
			newnode2->weight = Weight;
			//����ڶ������
			if (nodes[NextPos].Link == NULL)nodes[NextPos].Link = newnode2;
			else
			{
				TreeNode* node = nodes[NextPos].Link;
				while (node->Link)node = node->Link;
				node->Link = newnode2;
			}

			//�����Ѽ���Ķ������
			if (!nodes[Position].existence && !nodes[NextPos].existence)RealNodeCount = RealNodeCount + 2;
			else
				RealNodeCount++;

			//���Ѽ������еĶ�����
			nodes[Position].existence = true;
			nodes[NextPos].existence = true;

			return true;
		}
	}
};

#endif
