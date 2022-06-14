class Solution {
public:
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
        
        int left = 0, right = A.size() - k;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x - A[mid] > A[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        return vector<int>(A.begin() + left, A.begin() + left + k);
        /*int mindiffindex=0;
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
        return res;*/
    }
};