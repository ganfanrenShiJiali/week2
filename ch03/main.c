/*链表的游标实现*/

#include<stdio.h>
#include"head.h"

void InitializeCursorSpace(void)
{
	int i = 0;
	while (i < SpaceSize - 1)
	{
		CursorSpace[i].Next = i+1;
		i++;
	}
	CursorSpace[SpaceSize - 1].Next = 0;
}
static Position CursorAlloc(void)//申请一个空间，实际上是把0的下一个弹出
{
	Position P;
	P = CursorSpace[0].Next;
	CursorSpace[0].Next = CursorSpace[P].Next;
	return P;
}
static Position CursorFree(Position P)
{
	CursorSpace[P].Next = CursorSpace[0].Next;
	CursorSpace[0].Next = P;
}
List MakeEmpty(List L)
{
	Position P=CursorSpace[L].Next;
	if (!IsEmpty(L))
	{
		while (P)
		{
			CursorFree(L);
			L = P;
			P = CursorSpace[P].Next;
		}
	}
}
int IsEmpty(const List L)
{
	return CursorSpace[L].Next == 0;
}
int IsLast(const Position P, const List L)
{
	return CursorSpace[P].Next == 0;
}
Position Find(ElementType x, const List L)
{
	Position P = CursorSpace[L].Next;
	while (P&&CursorSpace[P].Element != x)
		P = CursorSpace[P].Next;
	return P;
}
void Delete(ElementType x, List L)
{
	Position P,TmpCell;
	P = FindPrevious(x, L);
	if (!IsLast(P, L))
	{
		TmpCell = CursorSpace[P].Next;
		CursorSpace[P].Next = CursorSpace[TmpCell].Next;
		CursorFree(TmpCell);
	}
}
Position FindPrevious(ElementType x, const List L)
{
	Position P;
	P = CursorSpace[L].Next;
	while (CursorSpace[P].Next&&CursorSpace[CursorSpace[P].Next].Element != x)
	{
		P = CursorSpace[P].Next;
	}
	return P;
}
void Insert(ElementType x, List L, Position P)
{
	Position TmpCell;
	TmpCell = CursorAlloc();
	if (TmpCell == 0)
		printf("Out of space!!!");
	CursorSpace[TmpCell].Element = x;
	CursorSpace[TmpCell].Next = CursorSpace[P].Next;
	CursorSpace[P].Next = TmpCell;
}
void DeleteList(List L)
{
	Position P, Tmp;
	P = CursorSpace[L].Next;
	CursorFree(L);
	while (P)
	{
		Tmp = CursorSpace[P].Next;
		CursorFree(P);
		P = Tmp;
	}
}
Position Header(const List L)
{
	return L;
}
Position First(const List L)
{
	return CursorSpace[L].Next;
}
Position Advance(const Position P)
{
	return CursorSpace[P].Next;
}
ElementType Retrieve(const Position P)
{
	return CursorSpace[P].Element;
}
void print(List L)
{
	Position P = CursorSpace[L].Next;
	while (P)
	{
		printf("%d", CursorSpace[P].Element);
		P = CursorSpace[P].Next;
	}
}
int main()
{
	int len, element;
	int i;
	InitializeCursorSpace();
	List L = 3;
	CursorSpace[L].Next = 0;
	CursorSpace[2].Next = 4;
	printf("请输入链表的长度：");
	scanf_s("%d", &len);
	printf("请依次输入链表中存取的数据：");
	Position P = L;
	for (i = 0; i < len; i++)
	{
		scanf_s("%d", &element);
		Insert(element, L, P);
		P = CursorSpace[P].Next;
	}
	printf("链表已初始化成功！！!\n");
	if (!IsEmpty(L))printf("链表非空\n");
	else printf("链表为空\n");
	printf("遍历打印链表:");
	print(L);
	return 0;
}
