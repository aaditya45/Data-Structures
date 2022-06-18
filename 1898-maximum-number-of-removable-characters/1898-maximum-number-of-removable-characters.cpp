class Solution {
public:
    
    bool isValid(vector<int>&removable,string s,string p,int mid){
        int a=0,b=0;
        int cnt=0;
        while(a<s.size()&&b<p.size()){
            bool flag=false;
            for(int i=0;i<mid;i++){
                if(a==removable[i]){
                    flag=true;
                    break;
                }
            }
            if(flag){
                a++;
                continue;
            }else{
                if(s[a]==s[b]){
                    b++;
                    cnt++;
                    //cout<<cnt<<endl;
                }
                a++;
            }
        }
        if(cnt!=p.size()) return false;
        return true;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int high=removable.size();
        int low=0;
        vector<int> mp(s.size(), INT_MAX);
        for(int i=0;i<removable.size();i++) mp[removable[i]]=i;
        while(high>low){
            int mid=(high+low+1)>>1;
            int j=0;
            for (int i=0;i<s.size()&&j<p.size();i++){
                if (mp[i] >= mid && s[i] == p[j]) j++;
            }
            if(j==p.size()){
                
                low=mid;
            }else high=mid-1;
        }
        return low;
    }
};