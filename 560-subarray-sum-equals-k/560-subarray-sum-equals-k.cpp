class Solution {
public:
    int subarraySum(vector<int>& pref, int k) {
        unordered_map<int,int> mp;
        for(int i=1;i<pref.size();i++) pref[i]+=pref[i-1];
        int cnt=0;
        for(int i=0;i<pref.size();i++){
            if(pref[i]==k) cnt++;
            if(mp[pref[i]-k]>=1){
                cnt+=mp[pref[i]-k];
            }
            mp[pref[i]]++;
        }
        return cnt;
    }
};