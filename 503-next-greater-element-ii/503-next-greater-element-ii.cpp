class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        unordered_map<int,int> mp;
        int M=nums.size();
        for(int i=0;i<2*nums.size();i++){
            while(!st.empty()&&nums[st.top()%M]<nums[i%M]){
                if(nums[i%M]==0) mp[st.top()%M]=INT_MAX;
                else mp[st.top()%M]=nums[i%M];//to avoid 0 problem of uost in c++
                st.pop();
            }
            st.push(i%M);
        }
        for(int i=0;i<nums.size();i++){
            if(mp[i]==0){
                nums[i]=-1;
            }else if(mp[i]==INT_MAX){
                nums[i]=0;
            }else{
                nums[i]=mp[i];
            }
        }
        return nums;
    }
};