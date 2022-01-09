#include <stdio.h>
#include <conio.h>
#include <malloc.h>
typedef struct node
{
int data;
struct node *left;
struct node *right;
}node;

node *insertElement(node *, int);
node *findElement(node *, int);
void preorderTraversal(node *);
void inorderTraversal(node *);
void postorderTraversal(node *);
node *findSmallestElement(struct node *);
node *findLargestElement(struct node *);
struct node *deleteElement(struct node *, int);
struct node *mirrorImage(struct node *);
int totalNodes(struct node *);
int totalExternalNodes(struct node *);
int totalInternalNodes(struct node *);
int Height(struct node *);
struct node *deleteTree(struct node *);
int main()
{
	int val;
	node *ptr;
	node *tree;
	tree = NULL;
	tree = insertElement(tree,45);
	tree = insertElement(tree,39);
	tree = insertElement(tree,56);
	tree = insertElement(tree,12);
	tree = insertElement(tree,34);
	tree = insertElement(tree,78);
	tree = insertElement(tree,32);
	tree = insertElement(tree,10);
	tree = insertElement(tree,89);
	tree = insertElement(tree,54);
	tree = insertElement(tree,67);
	inorderTraversal(tree);
	printf("\n");
	ptr = findElement(tree,56);
	tree = deleteElement(tree,78);
	inorderTraversal(tree);
	
	getch();
return 0;
}

node *insertElement(node *tree, int val)
{
	node *ptr, *nodeptr, *parentptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;
	
	if(tree==NULL)
	{
		tree=ptr;
	}
	else
	{
		if(val<tree->data)
			tree->left = insertElement(tree->left, val);
		else
			tree->right = insertElement(tree->right, val);
	}
	return tree;
}
node *findElement(node *tree, int val)
{
	node *ptr;
	if(tree->data == val || tree == NULL)
		return tree;
	else
	{
		if(val<tree->data)
			return findElement(tree->left,val);
		else
			return findElement(tree->right,val);
	}
	return tree;
}

node *deleteElement(node *tree, int val)
{
	node *temp;
	if(tree==NULL)
		return tree;
	else if( val < tree->data)
		tree->left = deleteElement(tree->left, val);
	else if ( val> tree->data)
		tree->right = deleteElement(tree->right, val);
	else if ( tree->left != NULL && tree->right != NULL)
	{
		temp =  findLargestElement(tree->left);
		tree->data = temp->data;
		tree->left = deleteElement(tree->left,temp->data);
	}
	else
	{
		if(tree->left == NULL && tree->right == NULL)
			tree = NULL;
		else if( tree->left != NULL)
			tree = tree->left;
		else
			tree = tree->right;
	}
	return tree;
}
void preorderTraversal(node *tree)
{
	if(tree != NULL)
	{
		printf("%d\t", tree->data);
		preorderTraversal(tree->left);
		preorderTraversal(tree->right);
	}
}
void inorderTraversal(node *tree)
{
	if(tree != NULL)
	{
		inorderTraversal(tree->left);
		printf("%d\t", tree->data);
		inorderTraversal(tree->right);
	}
}
void postorderTraversal(node *tree)
{
	if(tree != NULL)
	{
		postorderTraversal(tree->left);
		postorderTraversal(tree->right);
		printf("%d\t", tree->data);
	}
}
node *findSmallestElement( node *tree)
{
	if( (tree == NULL) || (tree->left == NULL))
		return tree;
	else
		return findSmallestElement(tree ->left);
}
node *findLargestElement(node *tree)
{
	if( (tree == NULL) || (tree->right == NULL))
		return tree;
	else
		return findLargestElement(tree->right);
}


