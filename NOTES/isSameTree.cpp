
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

    	//check to see if p and q are both null and if so return true;
        if(p == NULL && q == NULL)return true;
        //if q is equal to NULL OR p is equal to NULL return false;
        if(q == NULL || p == NULL) return false;
        
        if(p->val != q->val) return false;
        
        return isSameTree(p->right,q->right) && isSameTree(p->left,q->left);
    }

};