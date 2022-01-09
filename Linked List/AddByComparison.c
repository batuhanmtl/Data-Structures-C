#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
} ;

struct node *addByComparison(struct node *r, int data)
{
	if (r == NULL)
	{ // if linked list is empty
		r = (struct node *)malloc(sizeof(struct node));
		r->next = NULL;
		r->data = data;
		return r;
	}
	if (r->data > data)
	{ //if the linked list is not empty and that item is greater than the inserted item
		//root changes
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->next = NULL;
		temp->data = data;
		temp->next = r;
		return temp;
	}
	//if linked list is not empty
	struct node *iter = r;
	while (iter->next != NULL && iter->next->data < data)
	{
		iter = iter->next;
	}

	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->next = iter->next;
	iter->next = temp;
	temp->data = data;
	return r;
}

void *display(struct node *r) //view the list
{
	struct node *iter;
	if (r != NULL)
	{
		iter = r;
		while (iter != NULL)
		{
			printf("%d\t", iter->data);
			iter = iter->next;
		}
		printf("\n");
	}
	else
		printf("--List is empty--\n");
}

int main()
{
	struct node *root;
	root = NULL;

	root = addByComparison(root, 100);
	root = addByComparison(root, 30);
	root = addByComparison(root, 54);
	root = addByComparison(root, 85);
	root = addByComparison(root, 210);
	root = addByComparison(root, 78);

	display(root);

	return 0;
}
