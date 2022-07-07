class Solution {
public:
    int dp[101][101];
    bool helper(int idx1,int idx2,string s1,string s2,string s3){
        if(idx1+idx2==s3.size()) return true;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        return dp[idx1][idx2]=(idx1<s1.size()&&s1[idx1]==s3[idx1+idx2]&&helper(idx1+1,idx2,s1,s2,s3))||(idx2<s2.size()&&s2[idx2]==s3[idx1+idx2]&&helper(idx1,idx2+1,s1,s2,s3));
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        memset(dp,-1,sizeof(dp));
        return helper(0,0,s1,s2,s3);
    }
};