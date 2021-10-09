#include<stdio.h>
#include"head.h"

SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
Position Find(ElementType x, SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (x < T->Element)
		Find(x, T->Left);
	else if (x > T->Element)
		Find(x, T->Right);
	else
		return T;
}
Position FindMin(SearchTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}
Position FindMax(SearchTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Right == NULL)
		return T;
	else
		return FindMax(T->Right);
}
/*Position FindMax(SearchTree T)
{
	if (T != NULL)
		while (T->Right != NULL)
			T = T->Right;
	return T;
}*/
SearchTree Insert(ElementType x, SearchTree T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct TreeNode));
		if (T == NULL)
			printf("Out of space!!!");
		else
		{
			T->Element = x;
			T->Left = NULL;
			T->Right = NULL;
		}
	}
	else if (x < T->Element)
		T->Left = Insert(x, T->Left);
	else if (x > T->Element)
		T->Right = Insert(x, T->Right);
	return T;
}
SearchTree Delete(ElementType x, SearchTree T)
{
	Position TmpCell;
	if (T == NULL)
		printf("Element not found");
	else if (x < T->Element)
		T->Left = Delete(x, T->Left);
	else if (x > T->Element)
		T->Right = Delete(x, T->Right);
	else if(T->Left&&T->Right)
	{
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else
	{
		TmpCell = T;
		if (T->Left == NULL)
			T = T->Right;
		else if (T->Right == NULL)
			T = T->Left;
		free(TmpCell);
	}
	return T;
}
ElementType Retrieve(Position P)
{
	return P->Element;
}
int main()
{
	printf("开始插入···\n");
	SearchTree T = NULL;
	T=Insert(1, T);
	T=Insert(3, T);
	T=Insert(4, T);
	T=Insert(2, T);
	T=Insert(6, T);
	T=Insert(8, T);
	printf("完成插入\n");
	printf("最大值是%d\n", Retrieve(FindMax(T)));
	printf("最小值是%d\n", Retrieve(FindMin(T)));
	Delete(3, T);
	Find(6, T);
	return 0;
}
