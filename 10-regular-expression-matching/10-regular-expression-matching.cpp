class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,false));
        dp[0][0]=true;
        for(int i=1;i<=p.size();i++){
            for(int j=0;j<=s.size();j++){
                if(p[i-1]!='*'&&p[i-1]!='.'){
                    dp[j][i]=j&&dp[j-1][i-1]&&(s[j-1]==p[i-1]);
                }else if(p[i-1]=='*'){
                    dp[j][i]=dp[j][i-2]||(j&&dp[j-1][i]&&(s[j-1]==p[i-2]||p[i-2]=='.'));
                }else{
                    dp[j][i]=j&&dp[j-1][i-1];
                }
            }
        }
        /*for(auto x:dp){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }*/
        
        return dp[s.size()][p.size()];
    }
};