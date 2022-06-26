class Solution {
public:
    int waysToSplitArray(vector<int>& n) {
        long long sum=0;
        long long left_sum=0;
        for(int i=0;i<n.size();i++){
            sum+=n[i];
            
        }
        
        
        int res=0;
        for(int i=0;i<n.size()-1;i++){
            left_sum+=n[i];
            sum-=n[i];
            if(left_sum>=sum) res++;
        }
        return res;
    }
};