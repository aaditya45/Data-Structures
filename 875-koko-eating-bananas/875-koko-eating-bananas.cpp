class Solution {
public:
    bool isValid(vector<int>& piles,int mid,int h){
        long long int hours=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]<=mid){
                hours++;
            }else if(piles[i]>mid){
                int rounds=piles[i]/mid;
                if(piles[i]%mid==0){
                    hours+=rounds;
                }else{
                    hours+=rounds+1;
                }
            }
        }
        if(hours<=h) return true;
        else return false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int m_=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]>m_){
                m_=piles[i];
            }
        }
        int a=1,b=m_,mid=0,res=0;
        while(a<=b){
            mid=(a+b)>>1;
            if(isValid(piles,mid,h)){
                res=mid;
                b=mid-1;
            }else a=mid+1;

        }
        return res;
    }
};

