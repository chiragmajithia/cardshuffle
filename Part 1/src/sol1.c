#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <limits.h>

void initDeck(deck *d)
{
	/** Initializes Deck with null pointer and assigns funtions to the function pointers**/
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
		d->enqueue(d,i);
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
		d->enqueue(d,table[i]); //initializes queue in reverse..so dequeuing occurs correctly
	}
}

int checkTable(int *table, int N)
{
	/** Assumes the deck intialization is sequential -- we check if cards on table
		appear in sequence to check if the deck is restored to orignal order.
	**/
	for(int i = 0; i < N; i++)
	{
		if(table[i] != i)
		{
			return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[])
{
	int N;
	if(argc != 2) //Check if number of input the arguments are valid
	{
		printf("Invalid input arguments %d\n",argc);
		exit(0);
	}
	else
	{
		sscanf(argv[1], "%d", &N); //Loads argument in the variable N
		if(N < 0)	// check if N is positive (negative N is  not possible logically)
		{
			printf("invalid input / input overflowed (INT_MAX) %d\n",N);
			exit(0);
		}
	}

	deck d;	// Declare a deck
	int *table = malloc (sizeof (int) * N);  // array of 'cards' on table
	int table_cnt = 0;	//table_cnt - counts the number of elemets on table
	unsigned long int round = 0; // number of rounds to reset the sequence.

	initDeck(&d); // initialize deck
	populateDeck(&d,N); // intialize the deck with input sequence
	
	do
	{
		while(!d.isEmpty(&d)) //Simulating round;
		{
			table[N-1-table_cnt++] = d.dequeue(&d); //store cards in table variable in reverse order,
													// to avoid reversing of queue later
			if(!d.isEmpty(&d))	// if queue becomes empty, break
				d.enqueue(&d,d.dequeue(&d));	
		}
		transferDeck(&d,table,N); // transfering cards on table to deck

		table_cnt = 0; //reset table_cnt
		round ++;

		if(round == ULONG_MAX) //counting number of rounds will overflow at ULONG_MAX
		{
			printf("Counting Limit Overflowed %lu\n", ULONG_MAX);
			break;
		}
	 } while(!checkTable(table,N)); //check if the new sequence is equal to original

    printf("%lu\n", round );
	return 0;
}