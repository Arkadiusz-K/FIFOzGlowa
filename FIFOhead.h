#ifndef _FIFO_INCLUDE_
#define _FIFO_INCLUDE_

typedef struct tagQFIFOItem
{
	int Key;
	tagQFIFOItem* pNext;
}QFIFOItem;

typedef struct
{
	QFIFOItem* pHead;
	QFIFOItem* pTail;
}QueueFIFO;

int QFCreate( QueueFIFO* que );
int QFEmpty( QueueFIFO* que );
void QFEnqueue( QueueFIFO* que, int x );
int QFDequeue( QueueFIFO* que );
void QFClear( QueueFIFO* que ); 
void QFRemove( QueueFIFO* que );
void QFDel( QueueFIFO* que );

#endif