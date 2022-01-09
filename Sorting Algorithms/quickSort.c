#include <stdio.h>  
/* function that consider last element as pivot,  
place the pivot at its exact position, and place  
smaller elements to left of pivot and greater  
elements to right of pivot.  */  
int partition (int arr[], int start, int end)  
{  
	int j;
    int pivot = arr[end]; // pivot element  
    int i = (start - 1);  
  
    for (j = start; j <= end - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            int t = arr[i];  
            arr[i] = arr[j];  
            arr[j] = t;  
        }  
    }  
    int t = arr[i+1];  
    arr[i+1] = arr[end];  
    arr[end] = t;  
    return (i + 1);  
}  
  
/* function to implement quick sort */  
void quick(int arr[], int start, int end) /* arr[] = array to be sorted, start = Starting index, end = Ending index */  
{  
    if (start < end)  
    {  
        int p = partition(arr, start, end); //p is the partitioning index  
        quick(arr, start, p - 1);  
        quick(arr, p + 1, end);  
    }  
}  
  
/* function to print an array */  
void display(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        printf("%d ", arr[i]);  
}  
int main()  
{  
    int i,size;
	printf("Array Size? = ");
	scanf("%d",&size);
	printf("\n");
	int arr[size];
	
	for(i=0;i<size;i++){
		printf("Element %d = ",i+1);
		scanf("%d",&arr[i]);
		printf("\n");
	} 
   
   
   
   
    printf("Before sorting array elements are - \n");  
    display(arr, size);  
    quick(arr, 0, size - 1);  
    printf("\nAfter sorting array elements are - \n");    
    display(arr, size);  
      
    return 0;  
}  
