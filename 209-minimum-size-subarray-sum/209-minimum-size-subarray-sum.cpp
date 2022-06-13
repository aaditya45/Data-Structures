//13/06/2022
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(accumulate(nums.begin(),nums.end(),0)<target) return 0;
        int sum=0;
        int res=INT_MAX;
        int i=0;
        int j=0;
        while(i<nums.size()){
            sum+=nums[i];
            
            if(sum>=target){
                while(sum>=target&&i>=j){
                    res=min(res,i-j+1);
                    sum-=nums[j];
                    j++;
                }
            }
            i++;
        }
        
        
        return res;
    }
};