class Solution {
public:
    
  
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