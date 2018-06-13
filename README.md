# Queue-


//Queue.h

#ifndef __QUEUE_H__
#define __QUEUE_H__

#pragma once

typedef int DataType;
typedef struct Node
{
	DataType _data;
	struct Node*_pNext;
}Node, *PNode;

typedef struct Queue
{
	PNode _pHead;
	PNode _pTail;
}Queue;

//队列的初始化
void QueueInit(Queue* q);
PNode BuyNode(DataType data);
//入队列
void QueuePush(Queue* q, DataType data);
//出队列
void QueuePop(Queue* q);
//取队头元素
DataType QueueFront(Queue* q);
// 取队尾元素 
DataType QueueBack(Queue* q);
// 获取队列中元素的个数 
int QueueSize(Queue* q);
// 检测队列是否为空 
int QueueEmpty(Queue* q);
#endif //__QUEUE_H__



//Queue.c
#include "Queue.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void QueueInit(Queue* q)
{
	assert(q);
	q->_pHead = NULL;
	q->_pTail = NULL;
}

PNode BuyNode(DataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;

	return pNewNode;
}
void QueuePush(Queue* q, DataType data)
{
	assert(q);
	if (q->_pHead == q->_pTail && q->_pHead == NULL)
	{
		q->_pHead =q->_pTail = BuyNode(data);
		return;
	}

	q->_pTail->_pNext = BuyNode(data);
	q->_pTail = q->_pTail->_pNext;
}
void QueuePop(Queue* q)
{
	PNode pCur = NULL;
	assert(q);
	pCur = q->_pHead;
	if (pCur == NULL)
		return;

	q->_pHead = q->_pHead->_pNext;
	free(pCur);
	pCur = NULL;
}
DataType QueueFront(Queue* q)
{
	assert(q);
	if (q->_pHead == NULL)
		return -1;
	return q->_pHead->_data;

}

DataType QueueBack(Queue* q)
{
	assert(q);
	if (q->_pTail == NULL)
		return -1;
	return q->_pTail->_data;
}
int QueueSize(Queue* q)
{
	int count = 0;
	PNode pCur = NULL;
	assert(q);
	if (q->_pHead == q->_pTail && q->_pHead == NULL)
		return 0;
	pCur = q->_pHead;
	while (pCur)
	{
		++count;
		pCur = pCur->_pNext;
	}

	return count;
}
int QueueEmpty(Queue* q)
{
	assert(q);

	return q->_pHead == q->_pTail && q->_pHead == NULL;
}

//test.c

#include "Queue.h"
#include<stdio.h>

void TestQueueInit()
{
	Queue q;
	QueueInit(&q);

}
void TestQueuePush()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);


}
void TestQueuePop()
{
	Queue q;
	QueueInit(&q);
	QueuePop(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePop(&q);
	QueuePop(&q);

}
void TestQueueFront()
{
	Queue q;
	QueueInit(&q);
	printf("%d ", QueueFront(&q));

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	printf("%d ",QueueFront(&q));

}
void TestQueueBack()
{
	Queue q;
	QueueInit(&q);
	printf("%d ", QueueBack(&q));

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	printf("%d ", QueueBack(&q));
}

void TestQueueSize()
{
	Queue q;
	QueueInit(&q);
	printf("%d ",QueueSize(&q));

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	printf("%d ", QueueSize(&q));

}
void TestQueueEmpty()
{
	Queue q;
	QueueInit(&q);
	if (QueueEmpty(&q))
	{
		printf("空队列\n");
	}
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	if (QueueEmpty(&q))
	{
		printf("空队列\n");
	}
	else
	{
		printf("非空队列\n");
	}

}
int main()
{
	//TestQueueInit();
	//TestQueuePush();
	//TestQueuePop();
	//TestQueueFront();
	//TestQueueBack();
	//TestQueueSize();
	TestQueueEmpty();
	return 0;
}
