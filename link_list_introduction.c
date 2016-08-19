/* this a code in c to create a link_list and to display it */

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

/* new struct named node for link_list
 * It will contain a value and a address of the next node
 * In the new data type data is to store a new intiger and
 * next pointer is to point to the next node
 */
typedef struct node{ int data; struct node *next;} nd;

/* This function is to create a new node for the main 
 * function takinginputs from the users
 */
nd *head;
void create_nodes(){
    nd *p, *q;
    // this will allocate the memory dynamically in p 
    p = (nd *)malloc(sizeof(nd));
    
    // here we are using random function to genarate the numbers randomly
    
    p->data = rand()%50+10;  // rand()%range+value_to_start_with
    p->next = NULL;
    
    // To check where the node is
    if(head == NULL){
        head = p;
        return 1;   // q is current node. it will make p as current node
    } else { 
        q = head;
        /* to shift the whole link list to the end */
        while(q->next != NULL){
            q = q->next;
        }
        q->next = p;
    } // end of else
    
} // end of create_nodes function

/* this function is to print the nodes that has been created i.e. 
 * the hole link list.
 */
void print_node(){
    nd* p; p = head;
    printf("\n");

    if(head != NULL){
         while((p->next)!=NULL){
            printf("%d \t",p->data);
            p=p->next;
        }// end of while loop
    } else {
         printf("lima4");
        printf("the list is empty!!!!!!");
    }
   
    
    printf("\n"); 
    
} // end of void print function

// this is main function 
int main(void) {
	// initialise the parameters.....
	int n = 10;
	printf("GIVE THE NUMBER OF ELEMENTS IN THE LINK_LIST :  10 ");
	srand(time(NULL)); // to randomize the seed for rand function used later
	/*...creating a node named p...*/

	int i;
	for(i=0;i<=n;++i){
	    create_nodes();

	} // end of for loop

	
	print_node();
	
	return 0;
} // end of main function

