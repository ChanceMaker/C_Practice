#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 struct TreeNode{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL),right(NULL){}
 };
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
    void helper(TreeNode *root, vector<int> x){
        if(root == NULL)
            return;
        if(root->left != NULL)
            helper(root->left, x);
        x.push_back(root->val);
        if(root->right != NULL)
            helper(root->right,x);
    }

};
int main() {
    Solution answer;

    return 0;
}