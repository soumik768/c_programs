
#include<stdlib.h>
#include<stdio.h>





 /* program for Merge Sort */
/*--------------------------------------*/
/*---------------start------------------*/
/*--------------------------------------*/


// Merges two subarrays of a[].
// First subarray is a[b..c]
// Second subarray is a[c+1..d]
void merge(int a[], int b, int c, int d)
{
    int i, j, k;
    int p = c - b + 1;
    int q =  d - c;
 
    // create temp arrays //
    int temp1[p], temp2[q];
 
    for (i = 0; i < p; i++)
        temp1[i] = a[b + i];
    for (j = 0; j < q; j++)
        temp2[j] = a[c + 1+ j];
 
    /* Merge the temp arrays back into a[b..d]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = b; // Initial index of merged subarray

    while (i < p && j < q)
    {
        if (temp1[i] <= temp2[j])
        {
            a[k] = temp1[i];
            i++;
        }
        else
        {
            a[k] = temp2[j];
            j++;
        }
        k++;
        
    }
 
    /* Copy the remaining elements of temp1[], if there are any */
    while (i < p)
    {
        a[k] = temp1[i];
        i++;
        k++;
        
    }
 
    /* Copy the remaining elements of temp2[], if there are any */
    while (j < q)
    {
        a[k] = temp2[j];
        j++;
        k++;
        
    }

}
 
/* the function to sort the array */
void merge_sort(int a[], int b, int c)
{

    if (b < c)
    {
        
        int r = b+((c-b)/2);
  
        merge_sort(a, b, r);
        merge_sort(a, r+1, c);
 
        merge(a, b, r, c);
    }
    
 
}


 
/* Driver program to test above functions */
int main()
{   
    int n = rand()%100+50;
    int a[n];
    int i;
    for (int i = 0; i < n; ++i)
    {
         a[i] = rand()%1000+500;
    }
    
 
    printf("Given array is \n");
    for (i=1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("\n Comparison to sort is \n");
    merge_sort(a, 0, n);
    for (i=1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
    
    return 0;
}
