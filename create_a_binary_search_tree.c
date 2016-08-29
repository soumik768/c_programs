/* this c program is to create a binary search tree. Here I have taken some comstants 
 * likes total number of elements is 100, the values of the elements are randomlly 
 * allocated to each and every nodes.
 */


/* this c program is to create a binary tree
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
bst *get_node(){  // in order to get input from users change the get_node() to get_node(int data) 
    bst *tmp; // where the data will be stored ...
    tmp = (bst*)malloc(sizeof(bst)); // to 
    tmp->a = rand()%150+1;
    tmp->left = NULL;
    tmp->right = NULL;
    
    return(tmp);
}

/* this function is to insert the elements in a binary tree 
 * or to create a binary tree ...
 */
void insert(bst *tmp, bst *root){
    
    /* check if the tmp node data is greater than the root data
     * if is then send it to the right of the root else send it 
     * to the left to the left child.
     *----------------------------------------------------------
     * here we have used the recursion
     */
    if (tmp->a <= root->a) {
        
        /* check there is any elements or not if yes then send the
         * info for another recursion.............................
         * else make the temporary node a left child.....
         */
      if (root->left == NULL)
         root->left = tmp;
      else
         insert(root->left, tmp);
   }
 
   if (tmp->a > root->a) {
       
       /* check there is any elements or not if yes then send the
         * info for another recursion.............................
         * else make the temporary node a right child.....
         */
      if (root->right == NULL)
         root->right = tmp;
      else
         insert(root->right, tmp);
   }
}


int main(void) {
    
    int i;
    bst *root, *new_node;
    root = NULL;
    bst *get_node();
    srand(time(NULL));
    for(i=0; i<100; i++){
       new_node = get_node();
       if(root == NULL){
           root = new_node;
       } else {
           insert(new_node, root);
       }
    }
        
	
	return 0;
}

