#include <stdio.h>

void bubbleSort(int arr[],int size){ //the function that takes an array as a parameter
	int temp,i,j;
	for(i=0;i<size;i++){
		int sorted =1;
		for(j=size-1;j>i;j--){ // (i) missing return for transition
			
			if(arr[j-1]>arr[j]){
				sorted=0; //If it enters this section, it means that the array is not sequential.
				temp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;
			}
		}
		if(sorted)
		/*If no elements are replaced in the array we are passing through, 
		this means that the array is sequential.(best case)*/
		
		break;
	}
}

void display(int arr[],int size){
	int i;
	for(i=0;i<size;i++) printf("A[%d] = %d\t",i+1,arr[i]);
}

int main(){
	
	int i,j,size;
	printf("the size of the array : ");
	scanf("%d",&size);
	int arr[size];
	printf("\n");
	
	for(i=0;i<size;i++){
		printf("Element %d =",i+1);
		scanf("%d",&arr[i]);
		printf("\n");	
	}
	
	
	printf("Unsorted Array = ");
	display(arr,size);
	printf("\n");
	
	bubbleSort(arr,size);
	printf("Sorted Array = ");
	display(arr,size);
	
	
	
	
	return 0;
	
}

