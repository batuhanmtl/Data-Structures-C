#include <stdio.h>


int selectionsort(int A[],int size){ //ascending sort
	int temp,min,i,j;
	for(i=0;i<size-1;i++){
		min=i;
		for(j=i;j<size;j++){
			if(A[j]<A[min]) min=j;
		}
		temp=A[i];
		A[i]=A[min];
		A[min]=temp;
	}
	return A;
}

void display(int A[],int size){
	int i;
	for(i=0;i<size;i++) printf("A[%d] = %d\t",i+1,A[i]);
}
int main(){
	int i,j,size;
	printf("the size of the array : ");
	scanf("%d",&size);
	int A[size];
	printf("\n");
	
	
	for(i=0;i<size;i++){
		printf("elementary %d =",i+1);
		scanf("%d",&A[i]);
		printf("\n");	
	}
	printf("Unsorted Array = ");
	display(A,size);
	printf("\n");
	A[size]=selectionsort(A,size);
	printf("Sorted Array = ");
	display(A,size);
	
	
	return 0;
}
