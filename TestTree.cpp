#include <iostream>
struct TreeNode{
	int data;
	struct TreeNode* left;
	struct TreeNode*right;

};

struct TreeNode* newTreeNode(int data){
	struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));

	newNode->data = data;

	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}


int main(){
		/*create root*/
	  struct TreeNode *root = newTreeNode(1);   
	  /* following is the tree after above statement  
	  
	        1 
	      /   \ 
	     NULL  NULL   
	  */
	    
	  
	  root->left        = newTreeNode(2); 
	  root->right       = newTreeNode(3); 
	  /* 2 and 3 become left and right children of 1 
	           1 
	         /   \ 
	        2      3 
	     /    \    /  \ 
	    NULL NULL NULL NULL 
	  */
	  
  
	  root->left->left  = newTreeNode(4); 
	  /* 4 becomes left child of 2 
	           1 
	       /       \ 
	      2          3 
	    /   \       /  \ 
	   4    NULL  NULL  NULL 
	  /  \ 
	NULL NULL 
	*/

       return 0;
}