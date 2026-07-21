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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        reverse(postorder.begin(),postorder.end());
        return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
    }

    TreeNode* build(vector<int>& postorder,int postStart,int postEnd,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int>& mp){
        if(postStart>postEnd || inStart>inEnd){
            return nullptr;
        }
        TreeNode* node=new TreeNode(postorder[postStart]);
        int inRoot=mp[postorder[postStart]];
        int numsLeft=inRoot-inStart;

        node->right=build(postorder,postStart+1,postEnd-numsLeft,inorder,inRoot+1,inEnd,mp);
        node->left=build(postorder,postEnd-numsLeft+1,postEnd,inorder,inStart,inRoot-1,mp);

        return node;
    }
};