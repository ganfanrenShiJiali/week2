/*AVL树例程*/
#define Max(a,b)(((a)>(b))?(a):(b))
#ifndef  _Tree_H

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
typedef int ElementType;


AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType x, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType x, AvlTree T);
AvlTree Delete(ElementType x, AvlTree T);
ElementType Retrieve(Position P);
void PrintTree(AvlTree T);
static int Height(Position P);
static Position SingleRotateWithLeft(Position K2);
static Position SingleRotateWithRight(Position K2);
static Position DoubleRotateWithLeft(Position K3);
static Position DoubleRotateWithRight(Position K3);
#endif // ! _Tree_H

struct AvlNode
{
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};
