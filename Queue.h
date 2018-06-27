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
