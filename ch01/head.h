#include<stdio.h>
#include<stdlib.h>

#ifndef _QUEUE_H

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementType;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType x, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif

#define MinQueueSize 5
struct QueueRecord
{
	int Capacity;//容量
	int Front;//队头
	int Rear;//队尾
	int Size;//元素大小
	ElementType *Array;//数组
};
