class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        sort(p.begin(),p.end());
        vector<vector<int>> res(p.size(),vector<int>(2,-1));
        //for(auto x:p) cout<<x[0]<<endl;
        for(int i=0;i<p.size();i++){
            int cnt=p[i][1];
            for(int j=0;j<p.size();j++){
                if(res[j][0]==-1&&cnt==0){
                    res[j][0]=p[i][0];
                    res[j][1]=p[i][1];
                    break;
                }else if(res[j][0]==-1||p[i][0]<=res[j][0]){
                    cnt--;
                }
            }
        }
        return res;
    }
};