class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        vector<int> v(a.size()+b.size(),0);
        int i=0,j=0,k=0;
        while(i<a.size()&&j<b.size()){
            if(a[i]>b[j]){
                v[k]=b[j];
                j++;
                k++;
            }else{
                v[k]=a[i];
                i++;
                k++;
            }
        }
        while(i<a.size()){
            v[k]=a[i];
            i++;
            k++;
        }
        while(j<b.size()){
            v[k]=b[j];
            j++;
            k++;
        }
        
        //for(auto x:v) cout<<x<<" ";
        if(v.size()%2==0){
            int m=v.size()/2;
            int n=m-1;
            return (double)(v[m]+v[n])/2;
        }else{
            int m=v.size()/2;
            return (double)v[m];
        }
        
        
        
    }
};