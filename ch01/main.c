/*队列ADT数组实现*/

#include"head.h"
#include<stdio.h>

int IsEmpty(Queue Q)
{
	return Q->Size == 0;
}
int IsFull(Queue Q)
{
	return Q->Size == Q->Capacity;
}
Queue CreateQueue(int MaxElements)
{
	Queue Q;
	if (MaxElements < MinQueueSize)
		printf("Queue size is too small");
	Q = malloc(sizeof(struct QueueRecord));
	if (Q == NULL)
		printf("Out of space!!!");
	Q->Array = malloc(sizeof(ElementType)*MaxElements);
	if (Q->Array == NULL)
		printf("Out of space!!!");
	Q->Capacity = MaxElements;
	MakeEmpty(Q);
	return Q;
}
void DisposeQueue(Queue Q)
{
	if (Q != NULL)
	{
		free(Q->Array);
		free(Q);
	}
}
void MakeEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;//理解了
	Q->Rear = 0;
}
void Enqueue(ElementType x, Queue Q)
{
	if (IsFull(Q))
		printf("Full queue\n");
	else
	{
		Q->Size++;
		Q->Rear++;
		if(Q->Rear>Q->Capacity-1)
			Q->Rear = 0;
		Q->Array[Q->Rear] = x;
	}
}
ElementType Front(Queue Q)
{
	return Q->Array[Q->Front];
}
void Dequeue(Queue Q)
{
	if (IsEmpty(Q))
		printf("Empty queue\n");
	else
	{
		Q->Size--;
		Q->Front++;
		if (Q->Front > Q->Capacity - 1)
			Q->Front = 0;
	}
}
ElementType FrontAndDequeue(Queue Q)
{
	ElementType ret;
	if (IsEmpty(Q))
	{
		printf("Empty queue");
		return NULL;
	}
	else
	{
		Q->Size--;
		ret = Q->Array[Q->Front];
		Q->Front++;
		if (Q->Front > Q->Capacity - 1)
			Q->Front = 0;
		return ret;
	}
}
int main()
{
	printf("创建一个队列\n");
	Queue Q=CreateQueue(5);
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
