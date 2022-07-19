class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;
        for(auto n:nums2){
            while(!st.empty()&&st.top()<n){
                mp[st.top()]=n+1;//to avoid 0 problem of uost in c++
                st.pop();
            }
            st.push(n);
        }
        for(auto&n:nums1){
            if(mp[n]==0){
                n=-1;
            }else{
                n=mp[n]-1;
            }
        }
        return nums1;
    }
};