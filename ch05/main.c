#include<stdio.h>
#include"head.h"

AvlTree MakeEmpty(AvlTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
Position Find(ElementType x, AvlTree T)
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
Position FindMin(AvlTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}
Position FindMax(AvlTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Right == NULL)
		return T;
	else
		return FindMax(T->Right);
}
AvlTree Insert(ElementType x, AvlTree T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct AvlNode));
		if (T == NULL)
			printf("Out of space!!!");
		else
		{
			T->Element = x;
			T->Height = 0;
			T->Left = NULL;
			T->Right = NULL;
		}
	}
	else if (x < T->Element)
	{
		T->Left = Insert(x, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)
		{
			if (x < T->Left->Element)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
		}
	}
	else if (x > T->Element)
	{
		T->Right = Insert(x, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			if (x > T->Right->Element)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
		}
	}
	return T;
}
AvlTree Delete(ElementType x, AvlTree T)
{
	Position TmpCell;
	if (T == NULL)
		printf("Element not found");
	else if (x < T->Element)
		T->Left = Delete(x, T->Left);
	else if (x > T->Element)
		T->Right = Delete(x, T->Right);
	else if (T->Left&&T->Right)
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
void PrintTree(AvlTree T)
{
	if (T != NULL)
	{
		PrintTree(T->Left);
		printf("%d  ", T->Element);
		PrintTree(T->Right);
	}
}
static int Height(Position P)
{
	if (P == NULL)
		return -1;
	else
		return P->Height;
}
static Position SingleRotateWithLeft(Position K2)
{
	Position K1;
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), K2->Height) + 1;
	return K1;
}
static Position SingleRotateWithRight(Position K1)
{
	Position K2;
	K2 = K1->Right;
	K1->Right = K2->Left;
	K2->Left = K1;
	K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
	K2->Height = Max(Height(K2->Right), K1->Height) + 1;
	return K2;
}
static Position DoubleRotateWithLeft(Position K3)
{
	K3->Left = SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);
}
static Position DoubleRotateWithRight(Position K1)
{
	K1->Right = SingleRotateWithLeft(K1->Right);
	return SingleRotateWithRight(K1);
}
int main()
{
	AvlTree T = NULL;
	T = Insert(3, T);
	T = Insert(2, T);
	T = Insert(1, T);
	T = Insert(4, T);
	T = Insert(5, T);
	T = Insert(6, T);
	T = Insert(7, T);
	T = Insert(16, T);
	T = Insert(15, T);
	T = Insert(14, T);
	T = Insert(13, T);
	T = Insert(12, T);
	T = Insert(11, T);
	T = Insert(10, T);
	T = Insert(8, T);
	T = Insert(9, T);
	printf("插入完成，打印AVL树");
	PrintTree(T);
	return 0;
}
