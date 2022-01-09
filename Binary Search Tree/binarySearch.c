#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * left;
	struct node * right;
};

struct node *insert(struct node*tree,int val){
	if(tree==NULL){
		struct node*root=(struct node *)malloc(sizeof(struct node));
		root->left =NULL;
		root->right=NULL;
		root->data=val;
		return root;
	}
	if(tree->data < val){
		tree->right=insert(tree->right,val);
		return tree;
	}
	tree->left=insert(tree->left,val);
	return tree;
}

void traverse(struct node*tree){ 
	if(tree==NULL) return;
	printf("%d ",tree->data);
	traverse(tree->right);
	traverse(tree->left);
	
}

void traverseAsc(struct node*tree){ // ascending sort
	if(tree==NULL) return;
	traverseAsc(tree->left);
	printf("%d ",tree->data);
	traverseAsc(tree->right);
	
}
	
void traverseDesc(struct node*tree){ // descending sort
	if(tree==NULL) return;
	traverseDesc(tree->right);
	printf("%d ",tree->data);
	traverseDesc(tree->left);
	
}

int search(struct node* tree,int val){ //find the desired value
	if(tree==NULL) return -1;
	if(tree->data == val) return 1;
	if(search(tree->right,val)==1) return 1;
	if(search(tree->left,val)==1) return 1;
	
	return -1;
	
}

int max(struct node*tree){ // find the max value in tree
	while(tree->right!=NULL){
		tree=tree->right;
	}
	return tree->data;
}

int min(struct node*tree){ // find the min value in tree
	while(tree->left!=NULL){
		tree=tree->left;
	}
	return tree->data;
}
struct node * delete(struct node*tree,int val){
	if(tree==NULL) return NULL;
	if(tree->data == val){
		if(tree->left==NULL && tree->right==NULL) return NULL;
		if(tree->right!=NULL){
			tree->data =min(tree->right);
			tree->right=delete(tree->right,min(tree->right));
			return tree;
		}
		tree->data=max(tree->left);
		tree->left=delete(tree->left,max(tree->left));
		return tree;
		
	}
	if(tree->data < val){
		tree->right=delete(tree->right,val);
		return tree;
	}
	tree->left=delete(tree->left,val);
	return tree;
}

int main(){
	
	struct node*tree=NULL;
	tree=insert(tree,56);
	tree=insert(tree,200);
	tree=insert(tree,26);
	tree=insert(tree,190);
	tree=insert(tree,213);
	tree=insert(tree,18);
	tree=insert(tree,28);
	tree=insert(tree,12);
	tree=insert(tree,24);
	tree=insert(tree,27);
	
	
	
	traverseAsc(tree);
	printf("\n");
	traverseDesc(tree);
	printf("\n");
	
	printf("sought value : %d\n",search(tree,100));
	printf("sought value : %d\n",search(tree,24));
	printf("Max : %d \n",max(tree));
	printf("Min : %d \n",min(tree));
	
	tree=delete(tree,190);
	traverse(tree);
	printf("\n");
	tree=delete(tree,19);
	traverse(tree);
	printf("\n");
	tree=delete(tree,56);
	traverse(tree);
	
	
	return 0;
}
