class Solution {
public:
    int vis[101][101];
    bool dfs(int a,int b,vector<vector<int>>&g){
        if(a<0||b<0||a>=g.size()||b>=g[0].size()) return false;
        if(vis[a][b]) return true;
        if(g[a][b]==1) return true;
        vis[a][b]=1;
        bool dx=dfs(a,b+1,g);
        bool dxn=dfs(a,b-1,g);
        bool dy=dfs(a+1,b,g);
        bool dyn=dfs(a-1,b,g);
        
        return dx&&dxn&&dy&&dyn;
        
    }
    
    int closedIsland(vector<vector<int>>& g) {
        memset(vis,0,sizeof(vis));
        int res=0;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(vis[i][j]==0&&(g[i][j]==0)&&dfs(i,j,g)) res++;
            }
        }
        
        /*for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return res;
    }
};