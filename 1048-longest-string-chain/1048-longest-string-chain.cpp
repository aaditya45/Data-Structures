class Solution {
public:
    int dp[1001][1001];
    int solve(int i,vector<string>&words){
        int gmax=1;
        for(int j=i+1;j<words.size();j++){
            int lmax=1;
            if(dp[i][j]!=-1){
                return dp[i][j];
            }
            if(words[i].size()==words[j].size()-1){
                int cnt=0;
                int a=0;
                int b=0;
                for(int m=0;m<words[j].size();m++){
                    if(words[i][a]!=words[j][b]){
                        cnt++;
                        b++;
                    }else{
                        a++;
                        b++;
                    }
                }
                if(cnt==1){
                    lmax=1+solve(j,words);
                }
            }
            gmax=max(lmax,gmax);
            dp[i][j]=gmax;
        }
        return gmax;
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &left,string &right){
            return left.size()<right.size();
        });
        memset(dp,-1,sizeof(dp));
        int gmax=1;
        for(int i=0;i<words.size();i++){
            int lmax=solve(i,words);
            gmax=max(lmax,gmax);
        }
        return gmax;
    }
};