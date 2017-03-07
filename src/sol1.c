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
		d->enqueue(d,table[N-1-i]); //initializes queue in reverse..so dequeuing occurs correctly
	}
}

int gcd(int n1, int n2)
{
    if (n2==0)
        return n1;
    return gcd(n2, n1%n2);
}
 

long unsigned int findlcm(int arr[], int n)
{
   long unsigned ans = arr[0];
   for (int i=1; i<n; i++)
        ans = ( ((arr[i]*ans)) / (gcd(arr[i], ans)) );
    return ans;
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
	int table_cnt = 0, cnt = 0;
	unsigned long int round = 0;

	initDeck(&d);
	populateDeck(&d,N);
	
	while(!d.isEmpty(&d)) //Simulating round;
	{
			table[N-1-table_cnt++] = d.dequeue(&d);
			if(!d.isEmpty(&d))
			d.enqueue(&d,d.dequeue(&d));
	}

	int *group = malloc( sizeof (int) * N);
	int index;
	for(int i = 0; i < N; i++)
	{
		group[i] = 1;
	}

	for(int  i = 0; i <N; i++)
	{
		index = i;
		while( table[index] != i)
		{
			index = table[index];
			group[i] += 1;
		}
	}

    printf("%d\n", findlcm(group,N));
	return 0;
}