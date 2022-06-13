class Solution {
public:
    int dp[201][201];
    int solve(int level,int i,vector<vector<int>>&triangle){
        if(level==triangle.size()){
            return 0;
        }
        if(dp[level][i]!=-1) return dp[level][i];
        
        return dp[level][i]=min(triangle[level][i]+solve(level+1,i,triangle),triangle[level][i]+solve(level+1,i+1,triangle));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,triangle);
    }
};