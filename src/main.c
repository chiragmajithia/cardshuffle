#include <stdio.h>
#include "queue.h"
#include <limits.h>

void initDeck(deck *d)
{
	d->front = NULL;
	d->rear = NULL;
	d->enqueue = enqueue;
	d->isEmpty = isEmpty;
	d->dequeue = dequeue;
	d->showDeck = showDeck;
}

void populateDeck(deck *d, int N)
{
	/** Initializes Deck with 1-N elements representing each card **/
	for(int i = 0; i < N; i++)
	{
		d->enqueue(d,i+1);
	}
}

void transferDeck(deck *d, int *table, int N) //Ask if deck is to be reversed
{
	/** Transfers the cards on table to deck 
		Ask if the cards on table are to be reversed?
		If yes, you can use queue implementation directly on table
	**/
	if(!d->isEmpty(d))
	{
		printf("WIERD!!\n"); // Wierd Check
	}

	for(int i = 0; i < N; i++)
	{
		d->enqueue(d,table[N-1 - i]); //initializes queue in reverse..so dequeuing occurs correctly
	}
}

int checkTable(int *table, int N)
{
	/** Assumes the deck intialization is sequential -- we check if cards on table
		appear in sequence to check if the deck is restored to orignal order.
	**/
	for(int i = 0; i < N; i++)
	{
		if(table[i] != N-i)
		{
			return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[])
{
	int N;
	if(argc != 2)
	{
		printf("Invalid input arguments %d\n",argc);
		exit(0);
	}
	else
	{
		sscanf(argv[1], "%d", &N);
		if(N < 0)
		{
			printf("invalid input / input overflowed (INT_MAX) %d\n",N);
			exit(0);
		}
	}

	deck d;	
	int *table = malloc (sizeof (int) * N); //might implement stack!
	int table_cnt = 0;
	unsigned long int round = 0, cnt = 0;

	initDeck(&d);
	populateDeck(&d,N);
	
	do
	{
		while(!d.isEmpty(&d)) //Simulating round;
		{
			int c = d.dequeue(&d); // get the top most card
			if(++cnt % 2 != 0) 	   // odd cards go on table
			{
				table[table_cnt++] = c;
			}
			else	//even cards go in deck
			{
				d.enqueue(&d,c);
			}
		}
		transferDeck(&d,table,N);
		cnt = 0;
		table_cnt = 0;
		round ++;
		if(round % 1000000 == 0)
		{
			printf("round: %lu cnt = %lu \n", round, cnt );
			d.showDeck(&d);
		}
		if(round == ULONG_MAX)
		{
			printf("Counting Limit Overflowed %lu\n", ULONG_MAX);
			break;
		}
	 } while(!checkTable(table,N));

    printf("%d\n", round );
	return 0;
}