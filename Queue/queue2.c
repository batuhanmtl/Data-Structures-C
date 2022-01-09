#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node * next;
};
struct node * root=NULL;
struct node *end = NULL;

void enqueue(int data){
	if(root==NULL){
		root=(struct node*)malloc(sizeof(struct node));
		root->data=data;
		root->next=NULL;
		end=root;
	}
	else{
		end->next=(struct node*)malloc(sizeof(struct node));
		end->next->data =data;
		end=end->next;
		end->next=NULL;
		
	}
}

int dequeue(){
	if(root==NULL){
		printf("--Empty--");
		return -1;
	}
	int rvalue =root->data;
	struct node *temp=root;
	root=root->next;
	free(temp);
	return rvalue;
}

int main(){
	int i;
	for(i =0;i<20;i++){
		enqueue(i*10);
	}
	
	for(i= 0;i<13;i++){
		printf("%d ",dequeue());
	}
	printf("\n");
	for(i =0;i<20;i++){
		enqueue(i*10);
	}
	
	for(i= 0;i<30;i++){
		printf("%d ",dequeue());
	}

	
	return 0;
}
