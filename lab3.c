
/*
Lab3 

Description: This is an linked list application which allows users to create nodes and insert values into the nodes
from various different positions in the list. As well as looking over a specific node to see its contents. Application also allows
for deletion of nodes. This linked list a foundation needed for queus and stacks.

Atahan Kucuk

*/
#include <stdio.h>
#include <stdlib.h>

/* define node struct */
struct node
{
    char *fName; /*  first name*/
    char *lName; /*  last name */
    char *puid;
    int age;
    struct node *nextPtr;
};

/* declaring function prototypes */

int getnodenount(struct node *);
struct node *createlistnonodes();
struct node *createlistnode(char *, char *, char *, int);
void insert_front(struct node *, char *, char *, char *, int);
void insert_middle(struct node *, char *, char *, char *, int);
void insert_end(struct node *, char *, char *, char *, int);
void delete_front(struct node *);
void delete_middle(struct node *);
void delete_end(struct node *);
void traverse(struct node *);
void look_up_by_index(struct node *, int);


int main(){
struct node *headPtr;


/* Menu for user to select which function to run  

Also for the insert and create node funtions here is where the values are passed

Functionaltiy of this application was tested according to the usage order


*/
int choice;
while(1){
printf("                       MENU                                \n");
printf("1.  Create a list with no nodes and just a start pointer \n");
printf("2.  Create a list with a single node\n");
printf("3.  Insert a node at the front of the list\n");
printf("4.  Insert a node at the middle of the list\n");
printf("5.  Insert a node at the end of the list\n");
printf("6.  Delete a node at the front of the list\n");
printf("7.  Delete a node at the middle of the list\n");
printf("8.  Delete a node at the end of the list\n");
printf("9.  Traverse linked list\n");
printf("10. Look a particular node by an index number\n");
printf("11. Exit\n");
printf("Usage order: 1 - 2 - 3 - 5 - 4 - 5 - 9 - 10 - any of the delete functions (6-8) \n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch(choice){
case 1:

headPtr = createlistnonodes();
break;

case 2:

headPtr = createlistnode("Atahan","Kucuk","0030975517",21);
break;

case 3:

insert_front(headPtr,"Jack", "Smith", "0030806725", 19 );
break;

case 4:

insert_middle(headPtr, "Elizabeth", "Ivanov", "0030608547", 20);
break;

case 5:

insert_end(headPtr, "Luke", "Evans", "0030758420", 23);
break;

case 6:

delete_front(headPtr);
break;

case 7:

delete_middle(headPtr);
break;

case 8:

delete_end(headPtr);
break;

case 9:

traverse(headPtr);
break;

case 10:

look_up_by_index(headPtr, 2);
break;

case 11:
exit(0);
break;

default: 
printf("Please make a valid selection from (1-11)");
break;



}

}
return 0;

}

//Function to create a list with no nodes
struct node *createlistnonodes()
{
    struct node *new = malloc(sizeof(struct node));
    new->fName = NULL;
    new->lName = NULL;
    new->puid = NULL;
    new->age = 0;
    new->nextPtr = NULL;
    return new;
}

//Function to create a list with node
struct node *createlistnode(char *FN, char *LN, char *puid, int age)
{
    struct node *headPtr = createlistnonodes();
    struct node *new = malloc(sizeof(struct node));
    new->fName = FN;
    new->lName = LN;
    new->puid = puid;
    new->age = age;
    new->nextPtr = NULL;
    headPtr->nextPtr = new;
    return headPtr;
}

int getnodecount(struct node *headPtr)
{
    struct node *tmpPtr = headPtr;
    int i = 0;
    while (tmpPtr != NULL)
    {
        tmpPtr = tmpPtr->nextPtr;
        i++;
    }
    return i - 1;
}


// function to insert to front 
void insert_front( struct node *headPtr, char *FN, char *LN, char *puid, int age){
struct node *t;
t = (struct node*)malloc(sizeof(struct node));
t->fName = FN;
t ->lName = LN;
t ->puid = puid;
t->age = age ;



if(headPtr == NULL){
    headPtr = t;
    headPtr ->nextPtr = NULL;
    return;
}

t->nextPtr = headPtr->nextPtr ;
headPtr->nextPtr = t; 

printf("%s %s %s %d inserted from the front successfully.\n", FN, LN, puid , age);


} 

//function to insert into the middle
void insert_middle(struct node *headPtr, char *FN, char *LN, char *puid, int age){
struct node *temp = headPtr;
struct node *mid;
int pos = getnodecount(headPtr) / 2; /* declaring a int variable for middle index of the list */
mid = (struct node*)malloc(sizeof(struct node));
mid->fName = FN;
mid->lName = LN;
mid->puid = puid;
mid->age = age;
int i = 0;

while(i != pos +1){
    temp = temp->nextPtr;
    i++;
}

mid->nextPtr = temp->nextPtr;
temp->nextPtr = mid;


printf("%s %s %s %d inserted from the middle successfully.\n",FN, LN, puid , age );


}

//function to insert into the end
void insert_end(struct node *headPtr, char *FN, char *LN, char *puid, int age){
struct node *temp = headPtr;
struct node *end = malloc(sizeof(struct node));
while(temp != NULL){
    if(temp->nextPtr == NULL){
        
        end->fName = FN;
        end->lName = LN;
        end->puid = puid;
        end->age = age;
        end->nextPtr = NULL;
        temp->nextPtr = end;
        break;
    }
    temp = temp->nextPtr;
}

printf("%s %s %s %d inserted from the end successfully.\n",FN, LN, puid , age );


}

//function to delete from the beginning+
void delete_front(struct node *headPtr){
if (getnodecount(headPtr) >= 1)
    {
        struct node *Tofree = headPtr->nextPtr;
        struct node *tmpPtr = headPtr;
        tmpPtr->nextPtr = tmpPtr->nextPtr->nextPtr;
        free(Tofree);
        printf(" deleted from the front successfully.\n");

    }
    else
    {
        printf("No nodes eligible for freeing\n\n");
    }


}
//function to delete from the middle
void delete_middle(struct node *headPtr){
struct node *temp = headPtr;

int pos = getnodecount(headPtr) / 2; /* declaring a int variable for middle index of the list */
int i = 0;
while (i != pos){
    temp = temp->nextPtr;
    i++;

}
struct node *Tofree = temp->nextPtr;
temp->nextPtr = temp->nextPtr->nextPtr;
free(Tofree);
printf(" deleted from the middle successfully.\n");

}
// function to delete from the end
void delete_end(struct node *headPtr){
struct node *temp = headPtr;
while(temp!=NULL){
    if (temp->nextPtr->nextPtr == NULL){
        free(temp->nextPtr->nextPtr);
        temp->nextPtr = NULL;
        printf(" deleted from the end successfully.\n");
        break;
    }
    temp = temp->nextPtr;
}


}
// function to traverse 
void traverse(struct node *headPtr){

struct node *t;
t = headPtr;
if (t == NULL){
    printf("Linked list is empty\n");
    return;
}
int c = getnodecount(headPtr); /* Number of nodes in the linked list  */
printf("There are %d nodes in linked list.\n", c);
while (t->nextPtr != NULL) {

//Displays the elements of the linked list
printf("%s\n%s\n%s\n%d\n------------\n", t->fName, t->lName, t->puid, t-> age);
t = t->nextPtr;


}





}
// function to look up to a certain index
void look_up_by_index(struct node *headPtr, int key ){
int n;
int c = getnodecount(headPtr); /* Number of nodes in the linked list  */
printf("There are %d nodes in linked list.\n", c);
printf("Please select a node between 1-%d : \n", c);
scanf("%d", &key);
n = key - 1; /* since the linked list starts at zero it is needed to subtract 1 from the actual no of the node  */



if (n >= getnodecount(headPtr)){
    printf("Invalid Number\n");
}
else{
struct node *current = headPtr;

for(int i=0;i <= n; i++){
current = current ->nextPtr;
}
printf("%s %s %s %d These are the data stored in this node \n",current->fName, current->lName, current->puid, current->age);


}


}








