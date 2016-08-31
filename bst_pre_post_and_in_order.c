/* this c program is to create a binary tree
 * out 100 randomly generated numbers and to print it in
 * different orders like preorders postorder inorder etc.
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
    tmp->a = x;
    tmp->left = NULL;
    tmp->right = NULL;
    
    return(tmp);
}

/* this function is to insert the elements in a binary tree 
 * or to create a binary tree ...
 */
bst *insert(bst *root, int x ){
    
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

/* this function is to print the each level elements
 * it will consider the root as the level 1 and then it will
 * go down recursively and print out the level elements
 */
void InLevel(bst* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d \t", root->a);
    else if (level > 1)
    {
        InLevel(root->left, level-1);
        InLevel(root->right, level-1);
    }
}

/* this function is to compute the "height" of a tree.
 * the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
 */
int height(bst *root)
{
    /* first check if the root is empty or not if so then 
     * return 0. else get the hight using recursion
     */
    if (root==NULL)
        return 0;
    else
    {
        int height1 = height(root->left);
        int height2 = height(root->right);
 
        if (height1 > height2)
            return(height1+1);
        else return(height2+1);
    }
}

/* this function is to initiate the printing*/
void printInlevel(bst* root)
{
    int h = height(root);
    int i;
    printf("%d\n", h);
    for (i=1; i<=h; i++)
        InLevel(root, i);
}

/* this function is to create inorder printing*/
void inOrder(bst *head)
{
    bst *temp = head;
    if(temp==NULL)
        return;
    else
    {
        inOrder(temp->left);
        printf(" %d ",temp->a);
        inOrder(temp->right);
    }
}


/* this function is to create preorder printing*/
void preOrder(bst *head)
{
    bst *temp = head;
    if(temp==NULL)
        return;
    else
    {
        printf(" %d ",temp->a);
        preOrder(temp->left);
        preOrder(temp->right);
    }
}


/* this function is to create postorder printing*/
void postOrder(bst *head)
{
    bst *temp = head;
    if(temp==NULL)
        return;
    else
    {
        postOrder(temp->left);
        postOrder(temp->right);
        printf(" %d ",temp->a);
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
    printf("\nEnter the number of elements ::: InLevel : \n");
       printInlevel(root);
    printf("\nEnter the number of elements ::: preOrder : \n");
       preOrder(root);
    printf("\nEnter the number of elements ::: inOrder : \n");
       inOrder(root);
    printf("\nEnter the number of elements ::: postOrder: \n");
       postOrder(root);
       printf("\n");
}

