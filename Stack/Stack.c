#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct stack{  
	int data;
	struct stack *next;
};

struct stack *push(struct stack *r,int data){
	struct stack *new_node;
	new_node=(struct stack*)malloc(sizeof(struct stack));
	new_node->data=data;
 	if(r==NULL){
 		new_node->next=NULL;
 		r=new_node;
 		return r;
	}
	
	else{
		new_node->next=r;
		r=new_node;
		return r;
		
	}
}
struct stack *pop(struct stack *r){
	struct stack *iter;
	iter=r;
	if(r==NULL) return NULL;
	else if(r->next==NULL){
		free(r);
		return NULL;
	}
	else{
		r=r->next;
		free(iter);
		return r;
	}
}



void *show(struct stack *r){
	struct stack *iter;
	iter=r;
	if(r==NULL) printf("--List Empty--\n");
	else if(r->next==NULL) printf(" %d\n",r->data);
	else{
		while(iter!=NULL){
			printf(" %d",iter->data);
			iter=iter->next;
		}
		printf("\n");
	}
}





int main(){
	
	struct stack *root=NULL;
	show(root);
	getch();
	root=push(root,5);
	show(root);
	getch();
	root=push(root,10);
	show(root);
	getch();
	root=push(root,15);
	show(root);
	getch();
	root=push(root,20);
	show(root);
	
	root=pop(root);
	show(root);
	getch();
	root=pop(root);
	show(root);
	getch();
	root=pop(root);
	show(root);
	getch();
	root=pop(root);
	show(root);
	getch();
	

	
	
}

