class Solution {
public:
    int solve(int i,bool adj,vector<int>&n,vector<vector<int>>&dp){
        if(i==n.size()) return 0;
        if(dp[i][adj]!=-1) return dp[i][adj];
        
        if(adj){
            return dp[i][adj]=solve(i+1,false,n,dp);
        }else{
            return dp[i][adj]=max(n[i]+solve(i+1,true,n,dp),solve(i+1,false,n,dp));
        }
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(2,-1));
        return solve(0,false,nums,dp);
        
    }
};