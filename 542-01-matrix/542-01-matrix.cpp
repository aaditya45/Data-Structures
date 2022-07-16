class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) q.push({i,j});
                else mat[i][j]=-1;
            }
        }
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            level++;
            while(sz--){
                int a=q.front().first;
                int b=q.front().second;
                q.pop();
                if(a+1<n&&mat[a+1][b]==-1){
                    mat[a+1][b]=level;
                    q.push({a+1,b});
                }
                if(a-1>=0&&mat[a-1][b]==-1){
                    mat[a-1][b]=level;
                    q.push({a-1,b});
                }
                if(b+1<m&&mat[a][b+1]==-1){
                    mat[a][b+1]=level;
                    q.push({a,b+1});
                }
                if(b-1>=0&&mat[a][b-1]==-1){
                    mat[a][b-1]=level;
                    q.push({a,b-1});
                }
            }
        }
               
        return mat;
    }
};