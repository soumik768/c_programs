/* this is a winner tree in c language
 */


#include"stdio.h"
#include"math.h"
#include"time.h"
#include"stdlib.h"

#define max(a,b) ((a>b)?(a):(b))

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
	int n, i, j;
	printf("\ngive the number of elements for the array :\t");
	scanf("%d", &n);

	int a =2*n;

	int *bst=(int*)malloc(sizeof(int)*a);

	for(i=0;i<n;i++){
		bst[i]=0;
	}
	for(i=n;i<a;i++){
		scanf("%d",&bst[i]);
	}
	
	
	printf("\n");
	race(bst, a, n);
	for (i = 1; i < a; ++i)
	{
		printf(" %d ", bst[i]);
	}printf("\n");
	printf("the first best is %d\n", bst[1]);
}
