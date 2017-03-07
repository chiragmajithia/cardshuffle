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


unsigned long int gcd(unsigned long  int n1, unsigned long int n2)
{
	/** computes (recursively) gcd between to numbers (Used to compute LCM)**/
    if (n2==0)
        return n1;
    return gcd(n2, n1%n2);
}
 

unsigned long  int lcm(int arr[], int N)
{
	/** computes LCM of the elements in the arr **/
   long unsigned ans = arr[0], ans_old = arr[0]; //lcm can be really long!
   for (int i=1; i<N; i++)
	{			
		ans = ( ((arr[i]*ans)) / (gcd(arr[i], ans)) ); // LCM(n1,n2) = n1 * n2 / gcd(n1,n2)
		if(ans < ans_old) // Test if answer overflows -- it happens for few N
		{
			printf("Variable Overflowed! \n");
			return ans_old; //whatever the answer is, it is not true due to overflowing
		}
		ans_old = ans;
	}
    return ans;
}

int main(int argc, char *argv[])
{
	int N;
	if(argc != 2) //Check if number of inputs are valid
	{
		printf("Invalid input arguments %d\n",argc);
		exit(0);
	}
	else
	{
		sscanf(argv[1], "%d", &N); //Check if input is valid
		if(N < 0) // negtive length of sequence is logically not possible
		{
			printf("invalid input / input overflowed (INT_MAX) %d\n",N);
			exit(0);
		}
	}

	deck d;	//linked-list based queue for deck
	int *table = malloc (sizeof (int) * N); //array of cards on table
	int table_cnt = 0; //table_cnt: counts number of cards on tabel 
								

	initDeck(&d); // initialize deck with null deck_info ptrs and function ptrs
	populateDeck(&d,N); // populate deck with sequence of card info
	
	while(!d.isEmpty(&d)) //Simulating round;
	{
			table[N-1-table_cnt++] = d.dequeue(&d); //store cards in table variable in reverse order,
													// to avoid reversing of queue later
			if(!d.isEmpty(&d))	// if queue becomes empty, break
				d.enqueue(&d,d.dequeue(&d)); //if not empty, place the top card at the end of deck.
	}

	int *group = malloc( sizeof (int) * N); // assign memory for group
	int index; // stores the index to check for cannonical cycles
	for(int i = 0; i < N; i++)
	{
		group[i] = 1; //initialize each group to 1 - at least consists of 1 elements
	}

	// compute number of canoniocal cycles between the input sequence and sequence at the end of 1st round
	for(int  i = 0; i <N; i++)
	{
		index = i;
		while( table[index] != i)
		{
			index = table[index];
			group[i] += 1;
		}
	}

	// get lcm of all the cycles to compute the total rounds it would take to restore the input sequence.
    printf("%lu\n", lcm(group,N));
	return 0;
}