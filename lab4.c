/*
Lab4 

Description: Cod for using stacks and queues for data structures

Atahan Kucuk

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define node struct */
struct node
{
    char *FName; /*  first name*/
    char *LName; /*  last name */
    char *puid;
    int age;
    struct node *nextPtr;
}*HeadStackPtr,*HeadQueuePtr,*temp,*Stack2Ptr,*Queue2Ptr, *QueueRear;

/* Above are the pointer declarations for this code   */





/* declaring function prototypes */

void Push();
void Pop();
void Enqueue();
void Dequeue();
void StackIsEmpty();
void QueueIsEmpty();
void ClearStack();
void ClearQueue();
void DisplayStack();
void DisplayQueue();
void createEmptyStack();
void createEmptyQueue();
void stackcount();
void QueueCount();
int countS = 0;
int countQ = 0;





int main(){

    

    int choice;
    createEmptyStack();
    createEmptyQueue();
    while(1){
    printf(" \n                      MENU                                \n");
    printf(" 1. Pop - delete a node from Stack\n");
    printf(" 2. Push - add a node to Stack \n");
    printf(" 3. Enqueue - add a node to the Queue \n");
    printf(" 4. Dequeue - delete a node from the Queue\n");
    printf(" 5. Empty Queue - remove all the nodes from the Queue \n");
    printf(" 6. Empty Stack - remove all the nodes from the Stack \n");
    printf(" 7. Print Queue \n");
    printf(" 8. Print Stack \n");
    printf(" 9. Exit \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    int c;
    while((c = getchar()) != '\n' && c != EOF);
    switch(choice){
        case 1:

        Pop();
        break;

        case 2:

        Push();
        break;

        case 3:

        Enqueue();
        break;

        case 4:

        Dequeue();
        break;

        case 5:
        ClearQueue();
        break;

        case 6:
        ClearStack();
        break;
        
        case 7:
        DisplayQueue();
        break;

        case 8:
        DisplayStack();
        break;

        case 9:
        exit (0);
        break;

        default:
        printf(" Please make a valid selection from (1-9)");
        break;

    }

    }
    return 0;

}

/* creating a stack*/
void createEmptyStack(){
    HeadStackPtr = NULL;
}
/*  check if the stack is full  */

void StackIsEmpty(){
if(HeadStackPtr == NULL)
printf("\n Stack is empty");
else{
printf("\n Stack is not empty\n");
stackcount();
}

}

/* Function to push   */
void Push(){

char *FN = malloc(21 * sizeof(char));
char *LN = malloc(21 * sizeof(char));
char *puid = malloc(11 * sizeof(char));
int userage;

printf("Enter First Name : \n");
fgets(FN, 21, stdin);
printf("Enter Last Name : \n");
fgets(LN, 21, stdin);
printf("Enter your PUID : \n");
fgets(puid, 11, stdin);
printf("Enter your age : \n");
scanf("%d", &userage);




if(HeadStackPtr == NULL){
    HeadStackPtr = (struct node *)malloc(1*sizeof(struct node));
    HeadStackPtr->nextPtr = NULL;
    HeadStackPtr->FName = FN;
    HeadStackPtr->LName = LN;
    HeadStackPtr->puid = puid;
    HeadStackPtr-> age = userage;
}
else 
{
    temp=(struct node *)malloc(1*sizeof(struct node));
    temp->nextPtr = HeadStackPtr;
    temp->FName = FN;
    temp->LName = LN;
    temp->puid = puid;
    temp->age = userage;
    HeadStackPtr = temp;
}


countS++;

}

/*Function to pop the stack  */
void Pop(){

    Stack2Ptr = HeadStackPtr;
    if(Stack2Ptr == NULL){
        printf("\n Cannot pop from the empty stack");
        return;
    }
    else
    Stack2Ptr = Stack2Ptr->nextPtr;
    printf("Popped value: %s\n%s\n%s\n%d\n\n", HeadStackPtr->FName, HeadStackPtr->LName, HeadStackPtr->puid, HeadStackPtr-> age);
    free(HeadStackPtr);
    HeadStackPtr = Stack2Ptr;
    countS--;
    


}
/*Function to display the stack   */
void DisplayStack(){
Stack2Ptr = HeadStackPtr;

if(Stack2Ptr == NULL){
    StackIsEmpty();
    return;
}
while(Stack2Ptr != NULL){

    printf("%s\n%s\n%s\n%d\n------------\n", Stack2Ptr->FName, Stack2Ptr->LName, Stack2Ptr->puid, Stack2Ptr-> age);
    Stack2Ptr = Stack2Ptr->nextPtr;
}


}

/*Function to clear the stack   */
void ClearStack(){


struct node * clear;
while( HeadStackPtr != NULL){
     clear = HeadStackPtr->nextPtr;
     Pop();
     HeadStackPtr = clear;
}
HeadStackPtr = clear;

printf("\n All stack elements are removed");
countS = 0;


}
void stackcount(){
    printf("\n number of elements in the stack: %d ", countS);
}



/* Function to create empty Queue  */
void createEmptyQueue(){

    HeadQueuePtr = Queue2Ptr =  NULL;
}


/* Function to Display the Queue   */
void DisplayQueue(){

Queue2Ptr = HeadQueuePtr;

if((Queue2Ptr == NULL) && (QueueRear == NULL)){
    QueueIsEmpty();
    return;
}
while (Queue2Ptr != QueueRear){
  printf("\n Elements of this Queue : %s\n%s\n%s\n%d\n\n", HeadQueuePtr->FName, HeadQueuePtr->LName, HeadQueuePtr->puid, HeadQueuePtr-> age );
    Queue2Ptr = Queue2Ptr->nextPtr;
}
if(Queue2Ptr == QueueRear){
printf("\n Elements of this Queue : %s\n%s\n%s\n%d\n\n", HeadQueuePtr->FName, HeadQueuePtr->LName, HeadQueuePtr->puid, HeadQueuePtr-> age );

}



}

/*Function to Enqueue  */
void Enqueue(){

char *FIRST = malloc(21 * sizeof(char));
char *LAST = malloc(21 * sizeof(char));
char *PUID = malloc(11 * sizeof(char));
int AgeQ;

printf("Enter First Name : \n");
fgets(FIRST, 21, stdin);
printf("Enter Last Name : \n");
fgets(LAST, 21, stdin);
printf("Enter your PUID : \n");
fgets(PUID, 11, stdin);
printf("Enter your age : \n");
scanf("%d", &AgeQ);

if(QueueRear == NULL){
    QueueRear = (struct node * )malloc(1*sizeof(struct node));
    QueueRear->nextPtr = NULL;
    QueueRear->FName = FIRST;
    QueueRear->LName = LAST;
    QueueRear->puid = PUID;
    QueueRear->age = AgeQ;
    HeadQueuePtr = QueueRear;
}
else{
temp=(struct node *)malloc(1*sizeof(struct node));
QueueRear->nextPtr = temp;
temp->FName = FIRST;
temp->LName = LAST;
temp->puid = PUID;
temp->age = AgeQ;
temp->nextPtr = NULL;

}
countQ++;



}

/* Function to Dequeue  */
void Dequeue(){
    
Queue2Ptr = HeadQueuePtr;

if(Queue2Ptr == NULL){

printf("\n Cannot Display the elements of the Queue");
return;

}
else if(Queue2Ptr->nextPtr != NULL){
    
    Queue2Ptr = Queue2Ptr->nextPtr;
    printf("\n Dequed value: %s\n%s\n%s\n%d\n\n", HeadQueuePtr->FName, HeadQueuePtr->LName, HeadQueuePtr->puid, HeadQueuePtr-> age);
    free(HeadQueuePtr);
    HeadQueuePtr = Queue2Ptr;
}else{
    printf("\n Dequed value: %s\n%s\n%s\n%d\n\n", HeadQueuePtr->FName, HeadQueuePtr->LName, HeadQueuePtr->puid, HeadQueuePtr-> age );
    free(HeadQueuePtr);
    HeadQueuePtr = NULL;
    QueueRear = NULL;
}

countQ--;
}

/* Function to clear the Queue   */ 
void ClearQueue(){

struct node *clear;

while(HeadQueuePtr != NULL){

    clear = HeadQueuePtr->nextPtr;
    Dequeue();
    HeadQueuePtr = clear;
    
}
HeadQueuePtr = clear;

printf("\n All Queue are removed");
countQ=0;

}

/* Function to check the queue if its empty   */
void QueueIsEmpty(){
if((HeadQueuePtr == NULL) && (QueueRear == NULL)){
    printf("\n Queue empty");

}
else{
    printf("Queue is not empty");
    QueueCount();
    }

}

/*Function for Queue count   */
void QueueCount(){
    printf("\n Queue size : %d", countQ);
}





