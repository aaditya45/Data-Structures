class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                if(i>=2&&nums[i]<nums[i-2]){
                    if(cnt>0) return false;
                    nums[i]=nums[i-1];
                    cnt++;
                }else{
                    if(cnt>0) return false;
                    nums[i-1]=nums[i];
                    cnt++;
                }
            }
        }
        return true;
        
    }
};