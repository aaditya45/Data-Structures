class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(p.size()+1,vector<int>(s.size()+1,0));
        for(int i=0;i<p.size()&&p[i]=='*';i++) {
            dp[i+1][0]=1;
        }
        dp[0][0]=1;
        for(int i=1;i<p.size()+1;i++){
            for(int j=1;j<s.size()+1;j++){
                if(p[i-1]=='*'){
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
                }else if(p[i-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=(p[i-1]==s[j-1])&&dp[i-1][j-1];
                }
            }
        }
        return dp[p.size()][s.size()];
    }
};