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
     
    bool dfs(TreeNode *root,int targetSum){
        if(root==NULL) return false;
        if(targetSum-root->val==0 && root->left==NULL && root->right==NULL) return true;
        
        
        
        return dfs(root->right,targetSum-root->val)||dfs(root->left,targetSum-root->val);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        return dfs(root,targetSum);
    }
};