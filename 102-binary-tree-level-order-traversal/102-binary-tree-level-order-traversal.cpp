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
    void IterativeLevelOrder(TreeNode *root,vector<vector<int>> &ans){
        if(root == NULL) return;
        queue<TreeNode*> q;
        TreeNode *t = root;
        q.push(t);
        int ic =1;
        while(!q.empty()){
            int j = 1;
            int x =0;
            vector<int> v;
            while(j<=ic){
                t = q.front();
                q.pop();
                v.push_back(t->val);
                if(t->left!=NULL){
                    q.push(t->left);
                    x++;
                }
                if(t->right!=NULL){
                    q.push(t->right);
                    x++;
                }
                j++;
            }
            ans.push_back(v);
            ic = x;
        }
        
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        IterativeLevelOrder(root,ans);
        return ans;
    }
};