#ifndef QUEUE_H
#define QUEUE_H

/** Definition and Declaration of QUEUE implmentation used for Deck in our problem **/

typedef struct deck_element deck_element; // define a deck_elment
struct  deck_element
{
	int  n;
	struct deck_element *next;
};

typedef struct deck deck; // define a deck
struct deck
{
    deck_element *front,  *rear;
    void (*enqueue)(deck*,int);
    int (*isEmpty)(deck*);
    int (*dequeue)(deck*);
    void (*showDeck)(deck*);
};




void enqueue(deck* this, int info)
{
    
    /** Implements enqueue operation of the queue: Adding element to the end **/
	deck_element *newnode=(struct deck_element*)malloc(sizeof(struct deck_element)); //Assign Memory for new node
    newnode->n=info; //Assign info to the new node n

    if((this->front==NULL)&&(this->rear==NULL)) //Check if the new node is first node of the queue
    {
        this->front=newnode;      //Assign front to the new node
        this->rear=newnode;       //Assign rear to the new node
        this->rear->next=NULL;    // Assign next element to rear as NULL
    }
    else   //If the queue already has some element
    {
        this->rear->next=newnode; //assign newnode to the end of the queue
        this->rear=newnode;       // make the newnode as rear of the queue
        this->rear->next=NULL;    // set the next of the rear to NULL 
    }
}

int dequeue(deck* this)
{
    /** Implements dequeue operation of the queue: Removing element from the front **/
    int info;
    struct deck_element *temp;

    // Check for empty Queue
    if(this->front == NULL) return -1;  // return -1 if the "deck_element" is empty -- -1 is not a valid n (logically)
    else
    {
        info = this->front->n;     // retrieve the info from front node
        temp = this->front;           // get the pointer to the front node - to free it later
        this->front = this->front->next;    // set the front node to the next availble node
        free(temp);             // delete the original front node.
        
        if(this->front == NULL)       //if the front reaches rear, and rear is popped, the rear has to be reset.
        {
            this->rear = NULL;        //reseting the rear
        }
    }
    return info;                // Return popped character
}

void showDeck(deck* this)
{
    /** Traverses the deck_element **/
	deck_element *tmp  = this->front; // create a temporary node - which is used to traverse the queue
	int i = 0; // index - counting the elements in the queue

	printf("Displaying Deck\n"); //Notify on stdout
	while(tmp != NULL) // Till the temp node reaches end of the queue
	{
		printf("%d: %d\n",i,tmp->n); // Printing current node
		tmp = tmp -> next;    //Moving to next node
		i++;  //incrementing index
	}
}

int isEmpty(deck* this)
{
    /** Returns 1 if there are no elements in deck **/
    return (this->front == NULL);
}

#endif