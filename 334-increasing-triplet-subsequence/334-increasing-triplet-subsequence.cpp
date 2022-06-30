class Solution {
public:
    bool increasingTriplet(vector<int>& n) {
        vector<int> v;
        for(int i=0;i<n.size();i++){
            if(v.size()>=3) return true;
            vector<int>::iterator it=lower_bound(v.begin(),v.end(),n[i]);
            if(it==v.end()) v.push_back(n[i]);
            else *it=n[i];
        }
        if(v.size()>=3) return true;
        return false;
    }
};