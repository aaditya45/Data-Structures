class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& i) {
        vector<int> res;
        vector<pair<int,int>> arr;
        for(int j=0;j<i.size();j++){
            arr.push_back({i[j][0],j});
        }
        sort(arr.begin(),arr.end());
        for(int j=0;j<i.size();j++){
            int a=0,b=i.size()-1,mid=0,curr=-1;
            while(a<=b){
                mid=(a+b)>>1;
                if(arr[mid].first>=i[j][1]){
                    curr=mid;
                    b=mid-1;
                }else a=mid+1;
            }
            if(curr==-1) res.push_back(-1);
            else res.push_back(arr[curr].second);
        }
        return res;
    }
};