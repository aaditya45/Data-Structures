class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int i=0;
        int j=0;
        int res=0;
        long long int prod=1;
        while(j<nums.size()){
            prod*=nums[j];
            while(prod>=k){
                prod/=nums[i];
                i++;
            }
            res+=j-i+1;
            j++;
        }
        return res;
    }
};