class Solution {
public:
    int dp[51][51][51];
    int M=1e9+7;
    int solve(int a,int b,int mm,int m,int n){
        if(mm<0) return 0;
        if(a<0||b<0||a>=m||b>=n) return 1;
        if(dp[a][b][mm]!=-1) return dp[a][b][mm];
        return dp[a][b][mm]=((solve(a,b+1,mm-1,m,n)%M+solve(a+1,b,mm-1,m,n)%M)%M+(solve(a,b-1,mm-1,m,n)%M+solve(a-1,b,mm-1,m,n)%M)%M)%M;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solve(startRow,startColumn,maxMove,m,n);
    }
};