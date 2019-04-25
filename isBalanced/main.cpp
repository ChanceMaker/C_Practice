#include <iostream>
#include <vector>
#include <array>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){}
};
std::vector<int> createVectFromArray(std::array<int,5> x){
    std::vector<int> Vect;

    for(int i = 0; i < x.size(); i++){
        Vect.push_back(x[i]);
    }
    return Vect;
}

void inorderPrint(TreeNode * x){
    if(x == NULL)
        return;
    if(x->left != NULL)
        inorderPrint(x->left);
    std::cout << x->val << " ";
    if(x->right != NULL)
        inorderPrint(x->right);
}

class forest {
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
class Solution {

public:
    /**
     * Method to check if the tree is in fact balanced
     * @param root
     * The root of the tree object
     * @return
     * This function is returns a boolean value stating whether
     * the function is balanced or not.
     */
    bool isBalanced(TreeNode *root) {
        bool balanced = true;
        height(root,balanced);
        return balanced;
    }

    int height(TreeNode *b1, bool & bal){
        if (b1 == NULL ) {
            return false;
        }
        int L_Branch_H = height(b1->left, bal);
        int R_Branch_H = height(b1->right, bal);
        if(std::abs(L_Branch_H - R_Branch_H) > 1){
            bal = false;
        }
        return std::max(L_Branch_H, R_Branch_H) + 1;

    }
};
int main() {
    forest Btree;
    std::vector<int> vect;
    TreeNode * root;
    Solution ans;
    std::array<int,5> ary = {-10,-3,0,5,9};
    vect = createVectFromArray(ary);
    root = Btree.sortedArrayToBST(vect);
    inorderPrint(root);
    std::cout << "\nBalanced Tree :" << ans.isBalanced(root) ;

    return 0;
}