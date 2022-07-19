class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>> C;
        C.push_back({1});
        for(int i=1;i<n;i++){
            vector<int> v(i+1,0);
            C.push_back(v);
            C[i][0]=C[i][v.size()-1]=1;
            for(int j=1;j<v.size()-1;j++){
                C[i][j]=C[i-1][j-1]+C[i-1][j];
            }
        }
        return C;
    }
};