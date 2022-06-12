class Solution {
public:
    bool isSmaller(int mid,vector<int>&weights,int req_days){
        
        int sum=0;
        int days=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>mid) return false;
            
            if(sum+weights[i]>mid){
                days++;
                sum=weights[i];
            }else{
                sum+=weights[i];
            }
        }
        days++;
        if(days>req_days) return false;
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        //sort(weights.begin(),weights.end());
        int a=weights[0];
        int b=accumulate(weights.begin(),weights.end(),0);
        /*for(int i=1;i<weights.size();i++){
            weights[i]+=weights[i-1];
        }*/
        int mid=0;
        int res=0;
        while(a<=b){
            mid=(a+b)>>1;
            if(isSmaller(mid,weights,days)){
                res=mid;
                b=mid-1;
            }else a=mid+1;
            
            
        }
        return res;
    }
};