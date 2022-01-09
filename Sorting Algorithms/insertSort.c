#include <stdio.h>

void insertionSort(int arr[],int size){ //ascending sort
	int i,j,temp;
	for(i=1;i<size;i++){
		temp =arr[i];
		j=i-1;
		
		while(j>=0 && arr[j]>temp){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=temp;
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
	
	insertionSort(arr,size);
	printf("Sorted Array = ");
	display(arr,size);
	
	
	
	
	return 0;
	
}
