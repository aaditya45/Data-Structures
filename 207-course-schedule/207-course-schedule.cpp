class Solution {
public:
    //cycle detection
    bool dfs(int curr,vector<vector<int>>&adj,vector<int>&vis){
        if(vis[curr]==2) return false;
        vis[curr]=2;
        for(auto num:adj[curr]){
            if(vis[num]!=1&&!dfs(num,adj,vis)) return false;
        }
        vis[curr]=1;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(auto num:p){
            adj[num[0]].push_back(num[1]);
        }
        bool res=true;
        for(int i=0;i<n;i++){
            if(vis[i]!=1) res=res&&dfs(i,adj,vis);
        }
        return res;
        
    }
};