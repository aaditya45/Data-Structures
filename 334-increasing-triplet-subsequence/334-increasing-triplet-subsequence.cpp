class Solution {
public:
    bool increasingTriplet(vector<int>& n) {
        vector<int> v(2,INT_MAX);
        
        for(int i=0;i<n.size();i++){
            if(n[i]<=v[0]) v[0]=n[i];
            else if(n[i]<=v[1]) v[1]=n[i];
            else return true;
        }
        return false;
    }
};