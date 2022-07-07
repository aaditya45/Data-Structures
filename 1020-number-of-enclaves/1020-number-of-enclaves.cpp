class Solution {
public:
    int vis[501][501];
    bool dfs(int a,int b,vector<vector<int>>&g,int&cnt){
        if(a<0||b<0||a>=g.size()||b>=g[0].size()) return false;
        if(vis[a][b]) return true;
        if(g[a][b]==0) return true;
        vis[a][b]=1;
        cnt++;
        bool dx=dfs(a,b+1,g,cnt);
        bool dxn=dfs(a,b-1,g,cnt);
        bool dy=dfs(a+1,b,g,cnt);
        bool dyn=dfs(a-1,b,g,cnt);
        
        return dx&&dxn&&dy&&dyn;
        
    }
    int numEnclaves(vector<vector<int>>& g) {
        memset(vis,0,sizeof(vis));
        int res=0;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                int cnt=0;
                if(vis[i][j]==0&&(g[i][j]==1)&&dfs(i,j,g,cnt)) res+=cnt;
            }
        }
        return res;
    }
};