class Solution {
public:
    int dp[101];
    int solve(int i,string s,int n){
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i]; 
        if(n-i>=2){
            int num=10*(s[i]-48)+(s[i+1]-48);
            cout<<num<<endl;
            if(num>26) return dp[i]=solve(i+1,s,n);
            else return dp[i]=solve(i+1,s,n)+solve(i+2,s,n);
        }else{
            return dp[i]=solve(i+1,s,n);
        }
    }
    
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,s,s.size());
    }
};