/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	public:
    bool isSymmetric(TreeNode* root)
    {
          helper(root,root);
    }

    bool helper(TreeNode* R1, TreeNode* R2){
    	if(R1 == NULL && R2 == NULL)
    		return true;
    	if(R1 == NULL || R2 == NULL)
    		return false;
    	
    	return (R1->val == R2->val) && helper(R1->left,R2->left) && helper(R1->right,R2->right);
    }
};