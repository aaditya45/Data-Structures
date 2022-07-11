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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return  {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        int ic=1;
        while(!q.empty()){
            int x=0;
            for(int i=0;i<ic;i++){
                TreeNode *tmp=q.front();
                q.pop();
                if(i==ic-1) res.push_back(tmp->val);
                if(tmp->left!=NULL){
                    q.push(tmp->left);
                    x++;
                }
                if(tmp->right!=NULL){
                    q.push(tmp->right);
                    x++;
                }
            }
            ic=x;
        }
        return res;
    }
};