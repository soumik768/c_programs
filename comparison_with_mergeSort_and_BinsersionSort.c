/* comparisons between mergeSort and Binary version of insertion sort and insertion sort */
/* The thresh hold (from there merge sort is really taking less time) for the three sorts is around 54-56 */

#include<stdlib.h>
#include<stdio.h>
#include<time.h>


/* program for BINARY Insertion Sort*/
/*--------------------------------------*/
/*---------------start------------------*/
/*--------------------------------------*/



int binary_search(int a[], int n){
	int i,j, p, q, r, key, count =0;
	// initial key
	for(i=1	; i<n; i++){
		
		key = a[i];
		j = i-1;

		// to do binary search
		while(j<=n-2 && a[j]>key){
			p = i;
			q = 0;
			r = (p+q)/2;
			if(a[r]>key){			//to compair weither it is greater than key or not if it is greater than the key then it will do the first one if not then the second program
				p=r;
				key = a[r];
				
			} else if(a[r]<key) { 
				q=r;
				key = a[r];
				
			}
			count++;
			j++;				
		} 
		
	}
	return count;	

}



/* program for normal Insertion Sort*/
/*--------------------------------------*/
/*---------------start------------------*/
/*--------------------------------------*/



int insertion_sort(int a[], int n){

	int i, j, o, count=0;
	for(i=1	; i<n; i++){
		o= a[i];
		j=i-1;
		while(j>=0 && a[j]>o){

			a[j+1]=a[j];			a[j] = o; 
			j--;
			count++;	
		}
		
		
	}
	return count;
}




 /* program for Merge Sort */
/*--------------------------------------*/
/*---------------start------------------*/
/*--------------------------------------*/


// Merges two subarrays of a[].
// First subarray is a[b..c]
// Second subarray is a[c+1..d]
int merge(int a[], int b, int c, int d)
{
    int i, j, k, count = 0;
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
    clock_t start = clock();
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
        count++;
    }
 
    /* Copy the remaining elements of temp1[], if there are any */
    while (i < p)
    {
        a[k] = temp1[i];
        i++;
        k++;
        count++;
    }
 
    /* Copy the remaining elements of temp2[], if there are any */
    while (j < q)
    {
        a[k] = temp2[j];
        j++;
        k++;
        count++;
    }
    clock_t end = clock();

    return end-start;
}
 
/* the function to sort the array */
int merge_sort(int a[], int b, int c)
{
    double count;
    if (b < c)
    {
        
        int r = b+((c-b)/2);
  
        merge_sort(a, b, r);
        merge_sort(a, r+1, c);
 
        count = merge(a, b, r, c);
    }
    return count;
}
 
/* Driver program to test above functions */
int main()
{   
    int n, k;
    srand(time(NULL));
    for(k=2;k<200;k++){
    n = k;
    int a[n],b[n],c[n];
    int i;
    for (i = 0; i < n; ++i)
    {
         a[i] = rand()%1000+500;
    }
    
    double l = merge_sort(a, 0, n - 1);
    

    for (i = 0; i < n; ++i)
    {
         b[i] = rand()%1000+500;
    }
    
    clock_t start1 = clock();
    insertion_sort(b, n);
    clock_t end1 = clock();
    
    double l1 = end1-start1;
    for (i = 0; i < n; ++i)
    {
         c[i] = rand()%1000+500;
    }

    clock_t start2 = clock();
    binary_search(c,n);
    clock_t end2 = clock();
    double l2 = end2-start2;
    printf("\n Comparison to sort is \n");
    printf("%d at  %f        %f         %f\n", k, l, l1, l2);
    }
    return 0;
}
