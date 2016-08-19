/* bubble sort algorithm using pointers */

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

/* using pointer  */
// to swap the two elements from the array
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a= *b;
    *b = temp;
} 

// main bubble sort algorithm
void bubble_sort(int *a, int n){
    int i;
    for(i=0;i<n;i++){
        int j;
        for(j=0;j<n-1;j++){
          if(*(a+j)>*(a+(j+1))){
              swap((a+j), (a+(j+1)));
          }
        } 
    } // end of for loop 1
}// end of void function

// main function 
int main(){
    
    int *a;
    a = (int*)malloc(sizeof(int));
    srand(time(NULL));// to change the seed value quickly
    int i;
    for(i=0;i<10;i++){
        *(a+i)= rand()%100+50;
    }
    // to print the given array
    printf("\n The unsorted array is :\n");
    
    for(i=0;i<10;i++){
        printf("%d  ",*(a+i));
    }
    clock_t start = clock();
    bubble_sort(a, 10);
    clock_t end = clock();
     
    double min = end - start;
    
    // to print the sorted array
    printf("\n The sorted array is :\n");
    
    for(i=0;i<10;i++){
        printf("%d  ",*(a+i));
    }
    
    printf("\nAnd The time Taken By The algorithm is %f\n", min);
    
    return 0;
}
