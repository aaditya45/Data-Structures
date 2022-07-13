class Solution {
public:
    int maxProduct(vector<int>& n) {
        int imax=n[0],imin=n[0];
        int res=n[0];
        for(int i=1;i<n.size();i++){
            
            if(n[i]<0)
                swap(imin,imax);
            
            imax=max(imax*n[i],n[i]);
            imin=min(imin*n[i],n[i]);
            
            res=max(res,imax);
        }
        
        
        return res;
        
        // n^2 solution with last testcase returning in TLE
        // int res=n[0];
        // for(int i=0;i<n.size();i++){
        //     int prod=n[i];
        //     res=max(res,prod);
        //     for(int j=i+1;j<n.size();j++){
        //         prod*=n[j];
        //         res=max(res,prod);
        //     }
        // }
        // return res;
    }
};