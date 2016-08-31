/* this c program is to create a binary tree and 
 * to count the total leaves in the binary tree.....
 * out 100 randomly generated numbers and to print it
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* this data type is to create a node having two pointer
 * in order to crete the binary search tree ...........
 */
typedef struct Binary_search_tree{
    int a;                               // to store the data
    struct Binary_search_tree *left;     // to store the address of left child
    struct Binary_search_tree *right;    // to store the address of right child
} bst;


/* This function will create temporary node before insertion it to the main 
 * binary tree..
 */
bst *get_node(int x){  // in order to get input from users change the get_node() to get_node(int data) 
    bst *tmp; // where the data will be stored ...
    tmp = (bst*)malloc(sizeof(bst)); // to 
    tmp->a = x;  tmp->left = NULL; tmp->right = NULL; return(tmp);
}

/* this function is to insert the elements in a binary tree 
 * or to create a binary tree ...
 */
bst *insert(bst *root, int x){

    if(root==NULL)  root = get_node(x);
	else
	{
		if(root->a > x)
		    root->left = insert(root->left,x);
		else 
			root->right = insert(root->right,x);
	}

	return root;
}

/* to get the the leaf count we need to go to the very end of the each
 * brunch and find out which node does not have the both child
 * -------------------------------------------------------------------
 * leaf is node which does not have any child on both side..
 */

int leaf(bst *root){
	if(root == NULL){
		return 0;
	} else {
		if(root->left == NULL && root->right == NULL){
			return 1;
		} else{
			return leaf(root->left)+leaf(root->right);
		}
    	    
	}
}


int main(void) {
    
    int n,i;
    printf("\nEnter the number of elements in tree: ");
    scanf("%d",&n);

	int a[n];


    //Generates random no. 
	srand(time(NULL));

    printf("The random no. generated are : ");
	for (i = 0; i < n; ++i)	
	 {
	 	a[i] = rand()%1000;
	 	printf("%d \t", a[i]);
	 } printf("\n");

         bst* root = NULL;
	
	root = insert(root,a[0]);

	for(i=1;i<n;i++)
	{
		insert(root,a[i]);
	}

   printf("\n 	%d ",leaf(root));
   printf("\n");
}
