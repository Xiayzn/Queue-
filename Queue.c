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
