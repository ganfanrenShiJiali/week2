#include<stdio.h>
#include<stdlib.h>

#ifndef _QUEUE_H

struct Node;
struct QNode;
typedef struct Node *PtrToNode;
typedef struct QNode *Queue;
typedef PtrToNode Rear;
typedef int ElementType;

int IsEmpty(Queue Q);
Queue CreateQueue(void);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType x, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif

struct Node
{
	ElementType Element;
	PtrToNode Next;
};
struct QNode
{
	int Size;
	PtrToNode Front;
	PtrToNode Rear;
};
