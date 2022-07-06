class Solution {
public:
    void allzero(int i,int j,vector<vector<int>>&m){
        int a=0,b=0;
        while(b<m[0].size()){
            m[i][b]=0;
            b++;
        }
        while(a<m.size()){
            m[a][j]=0;
            a++;
        }
    }
    void setZeroes(vector<vector<int>>& m) {
        vector<pair<int,int>> coors;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j]==0){
                    coors.push_back({i,j});
                }
            }
        }
        for(auto coor:coors){
            allzero(coor.first,coor.second,m);
        }
    }
};