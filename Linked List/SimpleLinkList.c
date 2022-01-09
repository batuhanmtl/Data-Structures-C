#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/*                                  ADD AND REMOVE NODES FROM SIMPLE LINKED LIST                     */


struct node //NODE STRUCTURE
{
	int data;
	struct node *next;
};

struct node *insertBeg(struct node *r,int data) //add to the beginning of the node
{
	struct node *new_node, *iter; //a new node and an iteration node
	new_node = (struct node *)malloc(sizeof(struct node)); //create space in memory
	new_node -> data = data; //data of the new node
	if(r!=NULL) //if given node is not empty
	{
		new_node -> next = r;
	}
	else //if the list is empty the new node becomes root
	{
		new_node ->next =NULL;
	
		
	}
	
		return new_node;
	
}
struct node *insertEnd(struct node *r,int data) //add a node to the end of the list
{
	struct node *iter, *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = data;
	iter = r;
	if (r->next==NULL){
		r->next=new_node;
		new_node->next= NULL;
		return r;
	}
	else{
		while(iter-> next != NULL)
		iter= iter -> next;
	iter-> next = new_node;
	new_node -> next = NULL;
	
	return r;
	}
}

struct node *insertBetween(struct node *r,int data,int val) {

/*
this function adds between the list and the value of the first node of
the two nodes you want to add is the value "val" and after the value of "val" the insertion is done.
*/
	struct node *new_node, *temp, *iter;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = data;
	iter = r;
	temp= r->next;
	while(temp!=NULL && iter -> data != val)
	{
		iter = temp;
		temp = temp -> next;
	}
	if(temp!= NULL)
	{
		iter -> next=new_node;
		new_node -> next = temp;
  	}
	return r;
}

struct node *deleteBeg(struct node *r) //delete a node from the beginning of the list
{
	struct node *temp;
	temp = r;
	r = r -> next;
	free(temp);
	return r;	
}
struct node *deleteEnd(struct node *r) //delete a node from the end of the list
{
	struct node * iter;
	iter = r;
	if(iter->next == NULL){
		return NULL;
	}
	else{
		while(iter ->next ->next !=NULL){
			iter =iter->next;
		}
		free(iter->next);
		iter->next=NULL;
		return r;
		
	}
	
}
struct node *deleteNode(struct node *r,int val) //delete the given node from the list
{
	struct node *iter, *temp;
	iter= r;
	if(iter -> data == val) //if the value we want to delete is in the first node
	{
		
		r=deleteBeg(r);
		
		return r;
	}
	else
	{
		while(iter != NULL && iter -> data != val ){
			temp = iter;
			iter= iter -> next;
		}
		if(iter!=NULL){
			temp -> next = iter -> next;
			free(iter);
		}
		return r;
	}
}
void *display(struct node *r) //view the list
{
	struct node *iter;
	if(r!=NULL)
	{
		iter = r;
		while(iter != NULL)
		{
			printf("%d\t", iter -> data);
			iter = iter -> next;
			
		}
		printf("\n");
	}
	else printf("--List is empty--\n");	
}

int main()
{
    struct node*root=NULL; //create an empty node
	
	display(root);
	getch();
	
	root=insertBeg(root,1);
	display(root);
	getch();
	
	root=insertBeg(root,7);
	display(root);
	getch();
	
	insertBetween(root,5,7);
	display(root);
	getch();
	
	root=insertEnd(root,9);
	display(root);
	getch();
	
	insertBetween(root,6,1);
	display(root);
	getch();
	
	insertBetween(root,15,6);
	display(root);
	getch();
	
	insertBetween(root,21,15);
	display(root);
	getch();
	
	deleteNode(root,15);
	display(root);
	getch();
	
	deleteNode(root,21);
	display(root);
	getch();
	
	root=deleteBeg(root);
	display(root);
	getch();
	
	root=deleteEnd(root);
	display(root);
	getch();
	
	root=deleteEnd(root);
	display(root);
	
	root=deleteBeg(root),
	display(root);
	getch();
	
	
	
	
	return 0;
}








