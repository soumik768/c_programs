

#include<stdlib.h>
#include<stdio.h>

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
        if (temp1[i] < temp2[j])
        {
            a[k] = temp1[i];
            i++;
        } else if(temp1[i]==temp2[j]){
            a[k] = temp1[i];
            i++;
            printf("\nfound! %d  the number is twise in the array \n",a[k]);
        } else {
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


int main(){
	int n = rand()%50+30;
	int f= 2*n;
	int a[f], b[n];
	int i;
	for ( i = 0; i < n; ++i)
	{
		/* code */
		a[i]= rand()%1000+500;

		b[i]=rand()%1000+500;
	}

	int key = rand()%1500+500;
	int c[n];
	for(i=0;i<n;i++){
		c[i] = key -b[i];
	}
        
	for(i=n;i<f;i++){
	        a[i]=c[i-n];
	}
	
	merge_sort(a, 0, f);
	return 0;
}
