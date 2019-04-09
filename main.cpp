#include <iostream>
#include <string>
#include <vector>
#include <array>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5


 */
std::vector<int> createVectFromArray(std::array<int,5> x){
	std::vector<int> Vect;

	for(int i = 0; i < x.size(); i++){
		Vect.push_back(x[i]);
	}
	return Vect;
}
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    	
        return BtreeCreate(nums,0,nums.size() - 1);
    }
    TreeNode* BtreeCreate(std::vector<int>& nums ,int begin,int end){
    	//one node tree Case 1
    	if(begin == end){
    		TreeNode* treeStump = new TreeNode(nums[begin]);
    		return treeStump;
    	}
    	//Invalid tree situation
    	if(begin > end){
    		return NULL;
    	}

		int mid = (begin + end) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left  = BtreeCreate(nums,begin,mid - 1);
		root->right = BtreeCreate(nums,mid + 1,end);

		return root;
    }
};
int main(int argc, char const *argv[])
{
	Solution answer;
	std::vector<int> intVect;
	TreeNode* BTree;
	std::array<int,5> ary  = {-10,-3,0,5,9};
	intVect = createVectFromArray(ary);
	BTree = answer.sortedArrayToBST(intVect);
	return 0;
}