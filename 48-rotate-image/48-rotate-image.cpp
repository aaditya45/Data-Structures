class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n=m.size();
        int l=0;
        for(int j=0;j<n/2;j++){
            
            for(int i=0;i<n-1-2*l;i++){
                swap(m[n-1-l][i+l],m[n-1-i-l][n-1-l]);
                swap(m[n-1-i-l][n-1-l],m[0+l][n-1-i-l]);
                swap(m[0+l][n-1-i-l],m[i+l][0+l]);
            }
            
            l++;
        }
        
    }
};