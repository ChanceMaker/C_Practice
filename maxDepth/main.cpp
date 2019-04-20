#include <iostream>
#include <vector>
#include <array>
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x),left(NULL), right(NULL){}
};

void printVect(std::vector<int> &x){
    for (auto itr = x.begin(); itr != x.end(); itr++) {
        std::cout << *itr << " ";
    }
}
/**
 * In printTree uses a inorder print method to print the tree.
 * @param root
 * The root of the tree that you are trying to print.
 */
void printTree(TreeNode * root){
    if(root == NULL)
        return;
    if (root->left != NULL)
        printTree(root->left);
    std::cout << root->val << " ";
    if (root->right != NULL)
        printTree(root->right);

}

std::vector<int> createVectFromArray(std::array<int,5> x){
    std::vector<int> Vect;

    for(int i = 0; i < x.size(); i++){
        Vect.push_back(x[i]);
    }
    return Vect;
}
class treeStand{
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
    int maxDepth(TreeNode* root) {
        if(root != NULL)
            return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
        return 0;
    }

};
int main() {
    Solution answer;
    treeStand BTree;
    TreeNode * root;
    int maxD = 0;
    std::array<int,5> ary = {-10,-3,0,5,9};
    std::vector<int> vect;
    vect = createVectFromArray(ary);

    root = BTree.sortedArrayToBST(vect);

    maxD = answer.maxDepth(root);
    std::cout << " THE MAX DEPTH : "<< maxD;
    return 0;
}