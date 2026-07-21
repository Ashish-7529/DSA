class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, trees are identical
        if (!p && !q) return true;
        
        // If one is null or values mismatch, trees are not identical
        if (!p || !q || p->val != q->val) return false;
        
        // Check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};