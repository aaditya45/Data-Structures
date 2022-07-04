class Solution {
public:
    
    int solve(int i,int j,bool alice,vector<int>&p,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(alice){
            return dp[i][j]=max(p[i]+solve(i+1,j,false,p,dp),p[j]+solve(i,j-1,false,p,dp));
        }else{
            return dp[i][j]=min(solve(i+1,j,true,p,dp),solve(i,j-1,true,p,dp));
        }
        
    }
    
    bool stoneGame(vector<int>& p){
        int total=accumulate(p.begin(),p.end(),0);
        vector<vector<int>> dp(p.size(),vector<int>(p.size(),-1));
        int res=solve(0,p.size()-1,true,p,dp);
        /*for(auto x:dp){
            for(auto y:x) cout<<y<<" ";
            cout<<endl;
        }
        cout<<res<<endl;*/
        if(total-res>res) return false;
        else return true;
    }
};