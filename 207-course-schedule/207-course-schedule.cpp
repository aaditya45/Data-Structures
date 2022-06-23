class Solution {
public:
    int dp[2001];
    bool dfs(int curr,vector<vector<int>>&adj,vector<int>&vis){
        if(vis[curr]) return false;
        if(dp[curr]!=-1) return dp[curr];
        vis[curr]=1;
        for(auto num:adj[curr]){
            if(!dfs(num,adj,vis)) return dp[curr]=false;
        }
        vis[curr]=0;
        return dp[curr]=true;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(auto num:p){
            adj[num[0]].push_back(num[1]);
        }
        bool res=true;
        for(int i=0;i<n;i++){
            if(dp[i]!=-1) res=res&&dp[i];
            else res=res&&dfs(i,adj,vis);
        }
        return res;
        
    }
};