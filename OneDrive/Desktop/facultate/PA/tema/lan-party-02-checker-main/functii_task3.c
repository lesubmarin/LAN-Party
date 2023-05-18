#include "header.h"

Queue* createQueue()
{
	Queue* q;
	q = (Queue *)malloc(sizeof(Queue));
	if(q == NULL){ 
        return NULL;
    }	
	q->front = q->rear = NULL;
	return q;	
}

void enQueue(Queue* q, TEAM* blueteam, TEAM* redteam)
{
    NodeQueue* newNode = (NodeQueue*)malloc(sizeof(NodeQueue));
    newNode->team1 = (TEAM*)malloc(sizeof(TEAM));
    newNode->team2 = (TEAM*)malloc(sizeof(TEAM));
    *(newNode->team1) = *blueteam;
    *(newNode->team2) = *redteam;
    newNode->next = NULL;
    if(q->rear == NULL){
        q->rear = newNode;
    }
    else{
        (q->rear)->next = newNode;
        q->rear = newNode;
    }
    if(q->front == NULL){
        q->front = q->rear;
    }
}

void deQueue(Queue* q) 
{
    if(isEmptyQueue(q)){
        printf("Coada e goala!\n");
        return;
    }
    NodeQueue* temp = q->front;
    q->front = q->front->next;
    free(temp->team1);
    free(temp->team2);
    free(temp);
}

int isEmptyQueue(Queue* q)
{
	return(q->front == NULL);
}

void deleteQueue(Queue* q)
{
	NodeQueue* aux;
	while(!isEmptyQueue(q)){
		aux = q->front;
		q->front = q->front->next;
		free(aux);
	}
	free(q);
}

TEAM* top(Node* top)
{
	if(isEmpty(top)){
        puts("Stiva e goala.");
    }
	return top->team;
} 

void push(Node** top, TEAM* newteam) {
	Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->team = (TEAM*)malloc(sizeof(TEAM));
	*(newNode->team) = *newteam;
	newNode->next = *top;
	*top = newNode;
}

TEAM* pop(Node** top) 
{
	if(isEmpty(*top)){
        puts("Stiva e goala.");
    }
	Node* temp = (*top); 		
	TEAM* aux = temp->team;	
	*top = (*top)->next;
    free(temp->team);   		
	free(temp);
	return aux;
}

int isEmpty(Node* top)
{
	return top == NULL;
}
	
void deleteStack(Node** top)
{
	Node* temp;
	while(!isEmpty(*top)){
		temp = *top;
		*top = (*top)->next;
		free(temp);
    }
}

void printQueue(Queue* q, FILE* file)
{
    Queue* qcopy = createQueue();
    NodeQueue* current = q->front;
    while(current != NULL){
        enQueue(qcopy, current->team1, current->team2);
        current = current->next;
    }
    while(!isEmptyQueue(qcopy)){
            fprintf(file, "%-33s-%33s\n", qcopy->front->team1->name, qcopy->front->team2->name);
            deQueue(qcopy);
        }
    deleteQueue(qcopy);
}

void printWinners(Node* winners, FILE* file)
{
    Node* winnersCopy = NULL;
    Node* node = winners;
    while(node != NULL){
        push(&winnersCopy, node->team);
        node = node->next;
    }
    reverse(&winnersCopy);
    while(!isEmpty(winnersCopy)){
        fprintf(file,"%-34s-  %.2f\n", top(winnersCopy)->name, top(winnersCopy)->points);
        pop(&winnersCopy);
    }
    deleteStack(&winnersCopy);
}

int countTeams(Node* winners)
{
    Node* winnersCopy = NULL;
    Node* node = winners;
    while(node != NULL){
        push(&winnersCopy, node->team);
        node = node->next;
    }
    int counter = 0;
    while(!isEmpty(winnersCopy)){
        counter++;
        pop(&winnersCopy);
    }
    deleteStack(&winnersCopy);
    return counter;
}

void reverse(Node** node) 
{
    if(*node == NULL || (*node)->next == NULL){
        return;
    }

    Node* ogl = NULL;

    while(*node != NULL){
        Node* temp = *node;
        *node = (*node)->next;

        temp->next = ogl;
        ogl = temp;
    }
    *node = ogl;
}