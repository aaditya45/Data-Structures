class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n=c.size();
        int i=n-k;
        int j=n-1;
        int sum=0;
        for(j=i;j<n;j++){
            sum+=c[j];
        }
        int res=sum;
        
        for(j=0;j<k;j++){
            sum+=c[j];
            sum-=c[i];
            i++;
            res=max(res,sum);
        }
        return res;
    }
};