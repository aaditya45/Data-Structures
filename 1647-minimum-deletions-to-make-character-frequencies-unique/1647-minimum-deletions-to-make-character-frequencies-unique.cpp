class Solution {
public:
    int minDeletions(string s) {
        vector<int> alp(26,0);
        
        for(int i=0;i<s.size();i++){
            alp[s[i]-97]=alp[s[i]-97]+1;
        }
        sort(alp.begin(),alp.end());
        /*for(auto x:alp){
            cout<<x<<endl;
        }*/
        int res=0;
        for(int i=0;i<alp.size()-1;i++){
            if(alp[i]==0) continue;
            int a=i,b=i+1;
            while(a>=0&&alp[a]==alp[b]){
                if(alp[a]==0) break;
                alp[a]=alp[a]-1;
                res++;
                a--;
                b--;
            }
            
        }
        return res;
        
    }
};