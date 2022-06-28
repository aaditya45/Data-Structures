class Solution {
public:
    int findPeakElement(vector<int>& n) {
        int a=0;
        int b=n.size()-1;
        while(a<b){
            int mid=(a+b)>>1;
            if(n[mid]<n[mid+1]){
                a=mid+1;
            }else b=mid;
            
        }
        return a;
    }
};