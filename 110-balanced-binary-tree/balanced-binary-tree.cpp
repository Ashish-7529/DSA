/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int checkHeight(TreeNode* node) {
        if (node == nullptr) return 0;

        int lheight = checkHeight(node->left);
        if (lheight == -1) return -1;

        int rheight = checkHeight(node->right);
        if (rheight == -1) return -1;

        if (abs(rheight - lheight) > 1) return -1;

        return max(lheight, rheight) + 1;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};