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
	int RealNodeCount = 0;  //该成员变量变量可用于提前停止Kruskal算法
	TreeNode* nodes = NULL;
	MinSpanTree(int verCount)
	{
		nodes = new TreeNode[verCount];
	}
	~MinSpanTree()
	{

	}
	bool MSTinseart(int Position, int NextPos, int Weight) //该函数为bool型，插入前会判断是否成环，成环则返回false，不成环则插入树中并返回true
	{
		if (nodes[Position].existence && nodes[NextPos].existence)
			return false;    //判断是否成环，若成环则返回false
		else
		{
			//不成环则插入树
			TreeNode* newnode1 = new TreeNode();   //new一个新结点
			newnode1->nextpos = NextPos;    //赋值相应的变量
			newnode1->weight = Weight;
			//插入第一个结点
			if (nodes[Position].Link == NULL)nodes[Position].Link = newnode1;
			else
			{
				TreeNode* node = nodes[Position].Link;
				while (node->Link)node = node->Link;
				node->Link = newnode1;
			}

			TreeNode* newnode2 = new TreeNode();  //new第二个新结点
			newnode2->nextpos = Position;    //赋值相应的变量
			newnode2->weight = Weight;
			//插入第二个结点
			if (nodes[NextPos].Link == NULL)nodes[NextPos].Link = newnode2;
			else
			{
				TreeNode* node = nodes[NextPos].Link;
				while (node->Link)node = node->Link;
				node->Link = newnode2;
			}

			//更新已加入的顶点个数
			if (!nodes[Position].existence && !nodes[NextPos].existence)RealNodeCount = RealNodeCount + 2;
			else
				RealNodeCount++;

			//将已加入树中的顶点标记
			nodes[Position].existence = true;
			nodes[NextPos].existence = true;

			return true;
		}
	}
};

#endif
