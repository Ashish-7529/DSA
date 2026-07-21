/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool dir = true;
        while (!q.empty()) {
            int s = q.size();
            vector<int> temp;
            for (int i = 0; i < s; i++) {
                TreeNode* front = q.front();
                q.pop();
                temp.push_back(front->val);
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            if (!dir) {
                reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);
            dir = !dir;
        }
        return ans;
    }
};