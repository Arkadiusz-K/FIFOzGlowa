#include "stdafx.h"
#include <stdlib.h>
#include "FIFOhead.h"


int QFCreate( QueueFIFO* que )
{
	QFIFOItem* head = ( QFIFOItem* )calloc( 1, sizeof( QFIFOItem ) );
	if( !head )
	{
		printf( "Blad, QFCreate\n" );
		return 0;
	}
	que->pHead = head;
	que->pTail = head;
	return 1;
}


int QFEmpty( QueueFIFO* que )
{
	return !( que->pHead->pNext ); 
}


void QFEnqueue( QueueFIFO* que, int x )
{
	QFIFOItem* p = ( QFIFOItem* )calloc( 1, sizeof( QFIFOItem ) );
	if( !p )
	{
		printf( "Blad, QFEnqueue\n" );
		return;
	}
	p->Key = x;				// Nowy element otrzymuje wartosc przekazanej liczby pseudolosowej
	que->pTail->pNext = p;	// Stary ogon wskazuje na nowy element
	que->pTail = p;			// Nowy element staje siê ogonem
}


int QFDequeue( QueueFIFO* que )
{
	if( !QFEmpty( que ) )
	{
		int x = que->pHead->pNext->Key;
		QFDel( que );
		return x;
	}
	printf( "Blad, QFDequeue\n" );
	return 0;
}


void QFClear( QueueFIFO* que )
{
	while( !QFEmpty( que ) )
		QFDel( que );
}


void QFRemove( QueueFIFO* que )
{
	QFClear( que );
}


void QFDel( QueueFIFO* que )
{
	if( !QFEmpty( que ) )
	{
		QFIFOItem* p = que->pHead->pNext;	// Element za g³owa
        que->pHead->pNext = p->pNext;	// G³owa wskazuje na trzeci element
		
		if( QFEmpty( que) )	// jeœli nie ma elementów oprócz g³owy
		  que->pTail = que->pHead;			// G³owa jest jednoczeœnie ogonem
		free( p );
	}
	else
	{
		printf( "blad, pusta kolejka, QFDel\n" );
		return;
	}
}

