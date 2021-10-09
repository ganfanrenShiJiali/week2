/*二叉查找树例程*/
#ifndef  _Tree_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType x, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType x, SearchTree T);
SearchTree Delete(ElementType x, SearchTree T);
ElementType Retrieve(Position P);

#endif // ! _Tree_H

struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};
