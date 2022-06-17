class Solution {
public:
    
    /*
    Agar kisi number 'n' ko 2 me break karke 'x' nikalna h as a sub number, we need (n-1)/x operations to be applied
    */
    bool isValid(vector<int>&nums,int maxOperations,int mid){
        int totalOperations=0;
        for(auto num:nums){
            totalOperations+=(num-1)/mid;
        }
        return (totalOperations<=maxOperations);
    }
    
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int high=INT_MIN;
        for(int i=0;i<nums.size();i++) high=max(high,nums[i]);
        int low=1;
        int ans;
        while(low<=high){
            int mid=(high+low)>>1;
            if(isValid(nums,maxOperations,mid)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};  