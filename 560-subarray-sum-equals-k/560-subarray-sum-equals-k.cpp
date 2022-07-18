class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> pref;
        map<int,int> mp;
        int sum=0;
        for(auto x:nums){
            sum+=x;
            pref.push_back(sum);
        }
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(pref[i]==k) cnt++;
            if(mp[pref[i]-k]>=1){
                cnt+=mp[pref[i]-k];
            }
            mp[pref[i]]++;
        }
        return cnt;
    }
};