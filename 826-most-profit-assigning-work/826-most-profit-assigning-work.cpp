class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<pair<int,int>> v;
        for(int i=0;i<d.size();i++){
            v.push_back(make_pair(d[i],i));
        }
        sort(v.begin(),v.end(),[](pair<int,int>&left,pair<int,int>&right){
            return left.first<right.first;
        });
        int m=0;
        vector<int> l(v.size(),0);
        for(int i=0;i<v.size();i++){
            m=max(p[v[i].second],m);
            l[i]=m;
        }
        int res=0;
        for(int i=0;i<w.size();i++){
            int mid,a=0,b=v.size()-1,val=-1;
            while(a<=b){
                mid=(a+b)>>1;
                if(v[mid].first<=w[i]){
                    val=mid;
                    a=mid+1;
                }else b=mid-1;
            }
            if(val==-1) res+=0;
            else res+=l[val];
        }
        return res;
    }
};