#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left, *right;
};

struct node *insert(struct node *root, int x){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = x;
	temp -> left = temp-> right = NULL;

	if(root == NULL){
		root = temp;
	}
	if(x < root-> data){
		root -> left = insert(root->left, x);
	}
	if(x > root->data){
		root -> right = insert(root->right, x);
	}
	return (root);
}

void printPreorder(struct node* node) 
{ 
	if (node == NULL) 
		return; 

	printf("%d ", node->data); 
	printPreorder(node->left); 
	printPreorder(node->right); 
}

void printpostorder(struct node* node){
	if (node == NULL) 
		return; 

	printpostorder(node->left); 
	printpostorder(node->right);
	printf("%d ", node->data); 
}

void printinorder(struct node* node){
	if (node == NULL) 
		return; 

	printinorder(node->left);
	printf("%d ", node->data); 
	printinorder(node->right);
}


void main(){
	int tree[] = {22,31,44,54,67,33,23,46,88,2,3};
	int i;
	struct node *root = NULL;
	for (i=0; i <= 10; i++){
		root = insert(root, tree[i]);
	}

	printf("Preorder traversal : ");
	printPreorder(root);
	printf("\n\nInorder traversal : ");
	printinorder(root);
	printf("\n\nPostorder traversal : ");
	printpostorder(root);
}
