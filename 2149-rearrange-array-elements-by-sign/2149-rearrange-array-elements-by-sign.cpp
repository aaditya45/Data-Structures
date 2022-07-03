class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> negs;
        queue<int> pos;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                negs.push(nums[i]);
            }else{
                pos.push(nums[i]);
            }
        }
        int m=0;
        for(int i=0;i<nums.size();i++){
            if(!m){
                nums[i]=pos.front();
                pos.pop();
                m=1;
            }else{
                nums[i]=negs.front();
                negs.pop();
                m=0;
            }
        }
        return nums;
    }
};