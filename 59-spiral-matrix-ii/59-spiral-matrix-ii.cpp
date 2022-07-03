class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n,vector<int>(n,-1));
        int vis=1;
        int i=0,j=0;
        m[0][0]=vis;
        while(true){
            if(vis==n*n) break;
            while(i+1!=n&&m[j][i+1]==-1){
                i++;
                vis++;
                m[j][i]=vis;
            }
            while(j+1!=n&&m[j+1][i]==-1){
                j++;
                vis++;
                m[j][i]=vis;
            }
            while(i-1!=-1&&m[j][i-1]==-1){
                i--;
                vis++;
                m[j][i]=vis;
            }
            while(j-1!=-1&&m[j-1][i]==-1){
                j--;
                vis++;
                m[j][i]=vis;
            }
        }
        return m;
    }
};