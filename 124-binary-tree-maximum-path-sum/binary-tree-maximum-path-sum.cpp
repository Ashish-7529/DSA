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
public:
    int result = INT_MIN;

    int solve(TreeNode* node) {
        if (!node)
            return 0;

        int leftMaxPathSum = solve(node->left);
        int rightMaxPathSum = solve(node->right);

        int smallMaxPath = leftMaxPathSum + node->val + rightMaxPathSum;
        result = max(result, smallMaxPath);

        int bigMaxPath = max(node->val, node->val + max(leftMaxPathSum, rightMaxPathSum));
        result = max(result, bigMaxPath);

        return bigMaxPath;
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return result;
    }
};