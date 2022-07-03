class Solution {
public:
    int wiggleMaxLength(vector<int>& n) {
        int hill=1,cliff=1;
        for(int i=1;i<n.size();i++){
            if(n[i]>n[i-1]) cliff=hill+1;
            else if(n[i]<n[i-1]) hill=cliff+1;
            
        }
        return max(cliff,hill);
    }
};