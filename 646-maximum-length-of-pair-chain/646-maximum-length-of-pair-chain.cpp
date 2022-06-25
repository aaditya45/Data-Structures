class Solution {
public:
    int dp[1001][2004];
    int solve(int i,int prev,vector<vector<int>>&pairs){
        if(i==pairs.size()) return 0;
        if(dp[i][prev+1001]!=-1) return dp[i][prev+1001];
        if(pairs[i][0]>prev){
            return dp[i][prev+1001]=max(1+solve(i+1,pairs[i][1],pairs),solve(i+1,prev,pairs));
        }else{
            return dp[i][prev+1001]=solve(i+1,prev,pairs);
        }
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,-1001,pairs);
        
    }
};