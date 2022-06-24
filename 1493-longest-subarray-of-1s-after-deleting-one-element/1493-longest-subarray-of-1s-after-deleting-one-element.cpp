class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0;
        int prev=0,gmax=0;
        for(;j<nums.size();j++){
            if(nums[j]==0){
                if(i==j) gmax=max(gmax,prev);
                else if(nums[i]==0) gmax=max(gmax,prev+j-i-1),prev=j-i-1;
                else gmax=max(gmax,prev+j-i),prev=j-i;
                i=j;
            }
        }
        gmax=max(gmax,prev+j-i-1);
        return gmax;
    }
};