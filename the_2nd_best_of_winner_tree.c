/* This code is to find the second best winner in 
 * winning tree. In this program i have used rand 
 * function to generate the input.....
 */
 
#include"stdio.h"
#include"math.h"
#include"time.h"
#include"stdlib.h"

#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

void race(int bst[], int a, int b){
	if (b>0)
	{
		if(b%2==0){
			int i;
			for (i = b; i < a-1; ++i)
			{
				bst[i/2]=max(bst[i], bst[i+1]);
			}
			race(bst, a-b, b/2);
		} else {
			int i;
			for (i = a-1; i >b; i--)
			{
				bst[(i-1)/2]=max(bst[i], bst[i-1]);
			}
			race(bst, a-(b-1), ceil(b/2));
		}
		
	} else return;
}


	

	

int main(){
	srand(time(NULL));
	int n, i, j;
	printf("\ngive the number of elements for the array :\t");
	scanf("%d", &n);
	int p =n;

	int a =2*n;

	int *bst=(int*)malloc(sizeof(int)*a);
	int *A =(int*)malloc(sizeof(int)*a);
	int *g =(int*)malloc(sizeof(int)*a);

	for(i=0;i<n;i++){
		bst[i]=0;
		A[i]=0;
	}
	for(i=n;i<a;i++){
		// scanf("%d",&bst[i]);
		bst[i]	= rand()%1000;
		A[i]=bst[i];
	}
	
	race(bst, a, n);
	int s = bst[1];

	for(i=0;i<a;++i){
		if(A[i] == s){
			g[i]=0;
		} else {
			g[i] = A[i];
		}
	}
	for(i=1;i<a;i++){
		
		printf("%d   ",bst[i]);
		
	}printf("\n");
	for(i=1;i<n;i=i*2){

		if(bst[i]==s){
			j=bst[i+1];
			if(bst[2*i]==s){
				j=max(j,bst[2*i+1]);
			}else if(bst[2*i+1]==s){
				j=max(j,bst[2*i]);
			}
		}
	}
	printf("%d",j);
}
