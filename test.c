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
