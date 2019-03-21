#include <iostream>
//Tree examples in c++
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* newNode(int data){
	struct node*  new_node= (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

int main(){
	struct node * root = newNode(5);
	root->left = newNode(2);
	root-right = newNode(3);



}