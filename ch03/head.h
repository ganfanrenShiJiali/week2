#include<stdio.h>

#ifndef _Cursor_H

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

void InitializeCursorSpace(void);

List MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const Position P, const List L);
Position Find(ElementType x, const List L);
void Delete(ElementType x, List L);
Position FindPrevious(ElementType x, const List L);
void Insert(ElementType x, List L, Position P);
void DeleteList(List L);
Position Header(const List L);
Position First(const List L);
Position Advance(const Position P);
ElementType Retrieve(const Position P);
void print(List L);
#endif
struct Node
{
	ElementType Element;
	Position Next;
};

#define SpaceSize 11
struct Node CursorSpace[SpaceSize];
