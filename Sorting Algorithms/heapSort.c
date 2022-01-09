#include <stdio.h>  
/* function to heapify a subtree. Here 'i' is the   
index of root node in array arr[], and 'n' is the size of heap. */   
void heapify(int arr[], int size, int i)  
{  
    int largest = i; // Initialize largest as root  
    int left = 2 * i + 1; // left child  
    int right = 2 * i + 2; // right child  
    // If left child is larger than root  
    if (left < size && arr[left] > arr[largest])  
        largest = left;  
    // If right child is larger than root  
    if (right < size && arr[right] > arr[largest])  
        largest = right;  
    // If root is not largest  
    if (largest != i) {  
        // swap arr[i] with a[largest]  
        int temp = arr[i];  
        arr[i] = arr[largest];  
        arr[largest] = temp;  
          
        heapify(arr, size, largest);  
    }  
}  
/*Function to implement the heap sort*/  
void heapSort(int arr[], int size)  
{  
	int i;
    for (i = size / 2 - 1; i >= 0; i--)  
        heapify(arr, size, i);  
    // One by one extract an element from heap  
    for (i = size - 1; i >= 0; i--) {  
        /* Move current root element to end*/  
        // swap arr[0] with arr[i]  
        int temp = arr[0];  
        arr[0] = arr[i];  
        arr[i] = temp;  
          
        heapify(arr, i, 0);  
    }  
}  
/* function to print the array elements */  
void printArr(int arr[], int size)  
{  
	int i;
    for (i = 0; i < size; ++i)  
    {  
        printf("%d", arr[i]);  
        printf(" ");  
    }  
          
}  
int main()  
{  
    int size,i;
    printf("Array Size? ==> ");
    scanf("%d",&size);
    printf("\n");
    int arr[size];
    
    for(i=0;i<size;i++){
    	printf("Element %d = ",i+1);
    	scanf("%d",&arr[i]);
    	printf("\n");
	}
    
    
    
    
    printf("Before sorting array elements are - \n");  
    printArr(arr, size);  
    heapSort(arr, size);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(arr, size);  
    return 0;  
}  
