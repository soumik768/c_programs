/* this c program is to create a binary tree and 
 * to find the diameter of the binary tree.....
 * out 100 randomly generated numbers and to print it
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max(a,b) (((a)>(b))?(a):(b))



typedef struct node 
{
	int a;
	struct node *left;
	struct node *right;
}bst;


/* This function will create temporary node before insertion it to the main 
 * binary tree..
 */
bst *get_node(int x) {  // in order to get input from users change the get_node() to get_node(int data) 
    
    bst *tmp; // where the data will be stored ...
    tmp = (bst*)malloc(sizeof(bst));
    tmp->a = x;  tmp->left = NULL;   tmp->right = NULL; return(tmp);
}

/*
  Inserts the element in correct position i.e. if data < node->data insert it into right subtree
  and if it is less then insert it in left subtree.
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



int height(bst *root) {
   if (root == NULL)
      return 0;

      // find the height of each subtree
      int holc = height(root->left);
      int horc = height(root->right);

      return 1 + max(holc,horc);
}

// compute tree diameter recursively 
int diameter(bst *root) {
   if (root == NULL)
      return 0;

   // get height of each subtree
   int holc = height(root->left);
   int horc = height(root->right);

   // compute diameters of each subtree
   int dolc = diameter(root->left);
   int dorc = diameter(root->right);

   return max(holc+holc+1,max(dolc,dorc));
}


int main()
{
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

   printf("\n 	%d ",diameter(root));
   printf("\n");
	
}
