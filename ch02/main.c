#include"head.h"
#include<stdio.h>

int IsEmpty(Queue Q)
{
	return Q->Size == 0;
}
Queue CreateQueue(void)
{
	Queue Q;
	Q = malloc(sizeof(struct QNode));
	if (Q == NULL)
		printf("Out of space!!!");
	Q->Front = malloc(sizeof(struct Node));
	if (Q->Front == NULL)
		printf("Out of space!!!");
	Q->Size = 0;
	Q->Rear = Q->Front;
	Q->Front->Next = NULL;
	MakeEmpty(Q);
	return Q;
}
void DisposeQueue(Queue Q)
{
	PtrToNode Tmp;
	Tmp = Q->Front;
	while (Tmp != NULL)
	{
		Q->Rear = Tmp->Next;
		free(Tmp);
		Tmp = Q->Rear;
	}
	return NULL;
}
void MakeEmpty(Queue Q)
{
	if (Q == NULL)
		printf("Create queue first");
	else
	{
		while (!IsEmpty(Q))
			Dequeue(Q);
	}
}
void Enqueue(ElementType x, Queue Q)
{
	PtrToNode TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		printf("Out of space!!!");
	TmpCell->Element = x;
	TmpCell->Next = NULL;
	Q->Size++;
	Q->Front = Q->Front;
	Q->Rear->Next = TmpCell;
	Q->Rear = TmpCell;
}
ElementType Front(Queue Q)
{
	if(!IsEmpty(Q))
		return Q->Front->Next->Element;
	else
	{
		printf("Empty queue");
		return 0;
	}
}
void Dequeue(Queue Q)
{
	if (IsEmpty(Q))
		printf("Empty queue");
	else
	{
		PtrToNode front = Q->Front->Next;
		Q->Front->Next = front->Next;
		Q->Size--;
		free(front);
	}
}
ElementType FrontAndDequeue(Queue Q)
{
	if (IsEmpty(Q))
		printf("Empty queue");
	else
	{
		ElementType ret;
		PtrToNode front = Q->Front->Next;
		Q->Front->Next = front->Next;
		ret = front->Element;
		free(front);
		Q->Size--;
		if (IsEmpty(Q))
			Q->Rear = Q->Front;//如果是最后一个元素被删除，Rear指针指向空间一起被释放，需要重设
		return ret;
	}
}
int main()
{
	printf("创建一个队列\n");
	Queue Q=CreateQueue();
	if (IsEmpty(Q))
		printf("队列为空\n");
	else
		printf("队列非空\n");
	printf("依次入队\n");
	Enqueue(1, Q);
	Enqueue(2, Q);
	Enqueue(3, Q);
	Enqueue(4, Q);
	Enqueue(5, Q);
	printf("%d\n",FrontAndDequeue(Q));
	Enqueue(5, Q);
	Enqueue(5, Q);
	printf("%d\n", FrontAndDequeue(Q));
	printf("%d\n", FrontAndDequeue(Q));
	printf("%d\n", FrontAndDequeue(Q));
	printf("%d\n", FrontAndDequeue(Q));
	printf("%d\n", FrontAndDequeue(Q));
	printf("%d\n", FrontAndDequeue(Q));
	Enqueue(6, Q);
	printf("%d",Front(Q));
	DisposeQueue(Q);
	return 0;
}
