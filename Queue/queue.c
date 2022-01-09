#include <stdio.h>
#include <stdlib.h>

int *arr;
int rear=0 ,front=0,size=2,i;
int dequeue(){
	if(front==rear){
		printf("--Empty--");
		return -1;
	}
	if(rear-front<size/4){
		int * arr2=(int*)malloc(sizeof(int)*size/2);
		for(i=0;i<=rear-front;i++){
			arr2[i]=arr[front+i];
		}
		rear-=front;
		front=0;
		free(arr);
		size /=2;
		arr=arr2;
	}
	return arr[front++];
};

void enqueue(int data){
	if(arr==NULL){
		arr= (int*)malloc(sizeof(int)*2);
	}
	if(rear >= size){
		size*=2;
		int * arr2=(int *)malloc(sizeof(int)*size);
		for(i = 0;i<size/2;i++){
			arr2[i]=arr[i];
		}
		free(arr);
		arr=arr2;
	}
	arr[rear++]=data;
	
};
void recoverMem(){ // free up unused memory
	if(front==0) return ;
	
	for (i=0;i<size;i++){
		arr[i]=arr[i+front];
	}
	rear -= front;
	front=0;
}
int main(){
	
	for(i =0;i<20;i++){
		enqueue(i*10);
	}
	printf("Size : %d rear : %d front : %d \n",size,rear,front);

	for(i= 0;i<10;i++){
		printf("%d ",dequeue());
	}
	recoverMem();
	printf("Size : %d rear : %d front : %d \n",size,rear,front);
	
	for(i =0;i<20;i++){
		enqueue(i*10);
	}
	printf("Size : %d rear : %d front : %d \n",size,rear,front);
	
	for(i= 0;i<30;i++){
		printf("%d ",dequeue());
	}
	printf("Size : %d rear : %d front : %d \n",size,rear,front);

return 0;
}
