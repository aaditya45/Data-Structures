class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long sc) {
        sort(p.begin(),p.end());
        vector<int> res;
        for(auto x:s){
            int a=0,b=p.size()-1,mid,pnt=p.size();
            while(a<=b){
                mid=(a+b)>>1;
                if((long long )p[mid]*x>=sc){
                    pnt=mid;
                    b=mid-1;
                }else a=mid+1;
            }
            res.push_back(p.size()-pnt);
        }
        return res;
    }
};