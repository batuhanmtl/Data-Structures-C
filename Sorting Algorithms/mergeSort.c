#include <stdio.h>  
  
/* Function to merge the subarrays of arr[] */  
void merge(int arr[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
      
    int LeftArray[n1], RightArray[n2]; //temporary arrays  
      
    /* copy data to temp arrays */  
    for (i = 0; i < n1; i++)    
    LeftArray[i] = arr[beg + i];    
    for (j = 0; j < n2; j++)    
    RightArray[j] = arr[mid + 1 + j];    
      
    i = 0; /* initial index of first sub-array */  
    j = 0; /* initial index of second sub-array */   
    k = beg;  /* initial index of merged sub-array */  
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            arr[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            arr[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        arr[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        arr[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
  
void mergeSort(int arr[], int beg, int end)  
{  
    if (beg < end)   
    {  
        int mid = (beg + end) / 2;  
        mergeSort(arr, beg, mid);  
        mergeSort(arr, mid + 1, end);  
        merge(arr, beg, mid, end);  
    }  
}  
  
/* Function to print the array */  
void display(int arr[], int size)  
{  
    int i;  
    for (i = 0; i <size; i++)  
        printf("%d ", arr[i]);  
    printf("\n");  
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
    mergeSort(arr, 0, size - 1);  
    printf("After sorting array elements are - \n");  
    display(arr, size);  
    return 0;  
}  
