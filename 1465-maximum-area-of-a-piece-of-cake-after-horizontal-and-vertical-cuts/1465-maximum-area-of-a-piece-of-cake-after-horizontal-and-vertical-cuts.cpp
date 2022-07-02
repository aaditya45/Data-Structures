class Solution {
public:
    int maxArea(int hi, int wi, vector<int>& h, vector<int>& v) {
        int mod=1e9+7;
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        int y=h[0];
        int x=v[0];
        for(int i=1;i<h.size();i++) y=max(y,h[i]-h[i-1])%mod;
        y=max(y,hi-h[h.size()-1])%mod;
        for(int i=1;i<v.size();i++) x=max(x,v[i]-v[i-1])%mod;
        x=max(x,wi-v[v.size()-1])%mod;
        int res=((long)(x)*(long)(y))%mod;
        return res;
    }
};