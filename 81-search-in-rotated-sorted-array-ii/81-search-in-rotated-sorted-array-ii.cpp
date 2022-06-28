class Solution {
public:
    bool search(vector<int>& n, int target) {
        int a=0;
        int b=n.size()-1;
        while(a<=b){
            int mid=(a+b)>>1;
            if(n[mid]==target){
                return true;
            }
            if((n[mid]==n[a]) && (n[mid] == n[b])){
                a++;
                b--;
            }
            else if(n[mid]<=n[b]){//right is sorted
                if(n[mid]<target&&n[b]>=target){
                    a=mid+1;
                }else{
                    b=mid-1;
                }
            }else{//left is sorted
                if(n[mid]>target&&n[a]<=target){
                    b=mid-1;
                }else{
                    a=mid+1;
                }
            }
            
        }
        
        return false;
        
    }
};