#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{	struct node *temp;	
	int data;
	struct node *next;
};

struct node *insertBeg(struct node *r,int data)
{
	struct node *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = data;
	if(r != NULL)
	{
		r -> temp = new_node;
	}
	new_node -> next = r;
	new_node -> temp = NULL;
	r = new_node;
	return r;
}
struct node *insertEnd(struct node *r,int data)
{
	struct node *iter, *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = data;
	iter=r;
	while(iter -> next != NULL)
		iter = iter -> next;
	iter -> next = new_node;
	new_node -> temp = iter;
	new_node -> next = NULL;
	return r;
}
struct node *insertAfter(struct node *r,int data,int val)
{
	struct node *new_node, *iter;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = data;
	iter = r;
	while(iter!= NULL && iter -> data != val)
		iter = iter -> next;
	if(iter != NULL)
	{
		new_node -> temp = iter;
		new_node -> next = iter -> next;
		iter-> next -> temp = new_node;
		iter -> next = new_node;
	}
	return r;
}
struct node *deleteBeg(struct node *r)
{
	struct node *iter;
	if(r != NULL)
	{
		iter = r;
		r = r -> next;
		if(r != NULL)
			r -> temp = NULL;
		free(iter);
	}
	return r;
}
struct node *deleteEnd(struct node *r)
{
	if(r != NULL)
	{
		struct node *iter;
		iter = r;
		while(iter -> next != NULL)
			iter = iter -> next;
		if(r == iter)
			return NULL;
		iter -> temp -> next = NULL;
		free(iter);
	}
	return r;
}
struct node *deleteAfter(struct node * r,int val)
{
	struct node *iter, *temp2;
	iter =r;
	while(iter!=NULL && iter -> data != val)
		iter = iter -> next;
	if(iter != NULL && iter -> next != NULL)
	{
		temp2 = iter -> next;
		iter -> next = temp2 -> next;
		if(temp2 -> next!= NULL)
			temp2 -> next -> temp = iter;
		free(temp2);
	}
	return r;
}
struct node *display(struct node *r)
{
	struct node *iter;
	iter=r;
	while(iter!=NULL)
	{
		printf("%d\t", iter -> data);
		iter = iter -> next;
	}
	printf("\n");
	return r;
}
int main()
{
	struct node *root = NULL;
	
	
	root=insertBeg(root,1);
	display(root);
	getch();
	
	
	root=insertBeg(root,7);
	display(root);
	getch();
	
	root=insertEnd(root,9);
	display(root);
	getch();
	
	root=insertAfter(root,8,1);
	display(root);
	getch();
	
	root=deleteBeg(root);
	display(root);
	getch();
	
	root=deleteEnd(root);
	display(root);
	getch();
		
	root=deleteAfter(root,1);	
	display(root);
	getch();
	
	return 0;
}

