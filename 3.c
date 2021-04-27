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

void printPreorder(struct node* node)  //print the tree
{ 
	if (node == NULL) 
		return; 

	printf("%d ", node->data); 
	printPreorder(node->left); 
	printPreorder(node->right); 
}


void main(){
	int tree[] = {21,43,1,55,56,3,4,23,12,20};
	int i;
	struct node *root = NULL;
	for (i=0; i <= 10; i++){
		root = insert(root, tree[i]);
	}

	printPreorder(root);
}
