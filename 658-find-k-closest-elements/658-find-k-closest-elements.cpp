class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int mindiffindex=0;
        vector<int> res;
        for(int i=1;i<arr.size();i++){
            
            if(abs(arr[i]-x)<abs(arr[mindiffindex]-x)){
                mindiffindex=i;
            }
            
        }
        cout<<mindiffindex<<endl;
        
        int a=mindiffindex-1;
        int b=mindiffindex+1;
        res.push_back(arr[mindiffindex]);
        for(int i=1;i<k&&(a>=0||b<arr.size());i++){
            if(a<0){
                res.push_back(arr[b]);
                b++;
            }else if(b>=arr.size()){
                res.push_back(arr[a]);
                a--;
            }else{
                if(abs(arr[a]-x)<=abs(arr[b]-x)){
                    res.push_back(arr[a]);
                    a--;
                }else{
                    res.push_back(arr[b]);
                    b++;
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};