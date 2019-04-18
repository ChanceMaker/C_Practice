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
     TreeNode(int x) : val(x),left(NULL),right(NULL){}
 };
 TreeNode * createTree(vector<int> & x){

 }
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> pPost;
        vector<int> qPost;
        helper(p, pPost);
        helper(p, qPost);
        if (pPost == qPost) {
            return true;
        }
        return false;

    }
    void helper(TreeNode *root,vector<int> & x){
        if (root == NULL)
            x.push_back(NULL);
        if (root->left != NULL) {
            helper(root->left,x);
        }
        x.push_back(root->val);
        if (root->right != NULL) {
            helper(root->right, x);
        }
    }

};
int main() {
    Solution answer;

    return 0;
}