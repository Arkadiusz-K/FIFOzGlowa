#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include "FIFOhead.h"
#define SIZE 10

using namespace std;

int main()
{
	QueueFIFO* que = ( QueueFIFO* )calloc( 1, sizeof( QueueFIFO ) );
	if( !que )
	{
		printf( "Blad, main\n" );
		return 0;
	}

	if( !QFCreate( que ) )
	{
		printf( "Blad, main\n" );
		return 0;
	}

	srand( ( unsigned )time( NULL ) );
	for( int i = 0; i < SIZE; i++ )
		QFEnqueue( que, rand() % SIZE + 1 );

	for( int i = 0; i < SIZE; i++ )
		printf( "Wartosc wynosi: %d\n", QFDequeue( que ) );

	free( que );
	que = NULL;
	return 0;
}

