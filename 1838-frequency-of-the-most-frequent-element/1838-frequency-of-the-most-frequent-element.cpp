class Solution {
public:
    int maxFrequency(vector<int>& nums, long k) {
        int j=0;
        int i=0;
        int res=0;
        sort(nums.begin(),nums.end());
        for(i=0;i<nums.size();i++){
            k+=nums[i];
            int windowSize=(i-j+1);
            if((long)windowSize*nums[i]>k){
                k-=nums[j];
                j++;
            }
            res=max(res,i-j+1);
        }
        return res;
    }
};