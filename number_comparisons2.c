/* C program to count the number of invertions are there in an array */

#include<stdlib.h>
#include<stdio.h>


int merge(int a[], int b, int c, int d)
{
    int i, j, k, count=0;
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
           
        } else {
            a[k] = temp2[j];
            j++;
            count++;
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
    
    return count;
    
  
}
/* merge sort program */
int merge_sort(int a[], int b, int c)
{

    int count =0;
    if (b < c)
    {
        
        int r = b+((c-b)/2);
  
        count = merge_sort(a, b, r);
        count += merge_sort(a, r+1, c);
 
        count += merge(a, b, r, c);
    }
    
    return count;
}


int main(){
	int n = rand()%50+30;
	int a[n];
	int i;
	for( i = 0; i < n; ++i)
	{
		/* code */
		a[i] = rand()%1000+500;
	}

	printf("the number of inversions are %d\n",merge_sort(a, 0, n));
    
    return 0;
}




