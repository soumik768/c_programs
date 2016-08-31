/* this c program is to create a binary tree and 
 * to find the lowest common ancestor in the binary tree.....
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
    tmp->a=x;
    tmp->left = NULL;
    tmp->right = NULL;
    
    return(tmp);
}

/* this function is to insert the elements in a binary tree 
 * or to create a binary tree ...
 */ 
bst* insert(bst *root , int x)
{ 
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

    
/* this function is to find the lca between two nodes n1 and n2 but
 * assumtions is that the both n1 and n2 is present in the 
 */
bst *lca(bst* root, int n1, int n2)
{
    if (root == NULL) return NULL;
 
    // If both n1 and n2 are smaller than root, then LCA lies in left
    if (root->a > n1 && root->a > n2)
        return lca(root->left, n1, n2);
 
    // If both n1 and n2 are greater than root, then LCA lies in right
    if (root->a < n1 && root->a < n2)
        return lca(root->right, n1, n2);
 
    return root;
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
  int n1, n2;
  scanf("%d %d", &n1, &n2);
  bst *t = lca(root, n1, n2);
  printf("LCA of %d and %d is %d \n", n1, n2, t->a);
        
	
	return 0;
}
