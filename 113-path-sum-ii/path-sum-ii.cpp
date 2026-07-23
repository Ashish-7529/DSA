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

    void solve(TreeNode *root, int tar, vector<vector<int>> &ans, vector<int>&curr)
    {
        if(root==NULL) return;

        if(root->val==tar  &&  root->left==NULL  &&  root->right==NULL)
        {
            curr.push_back(root->val);
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        else curr.push_back(root->val);

        solve(root->left,tar-root->val,ans,curr);
        solve(root->right,tar-root->val,ans,curr);

        curr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;

        solve(root,targetSum,ans,temp);

        return ans;
    }
};