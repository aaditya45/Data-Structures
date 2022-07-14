class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n<=1) return 1;
        if(dp[n]!=0) return dp[n];
        for(int i=1;i<=n;i++){
            dp[n]+=solve(i-1,dp)*solve(n-i,dp);
        }
        return dp[n];
    }
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        return solve(n,dp);
    }
};