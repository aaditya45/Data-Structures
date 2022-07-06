class Solution {
public:
    int vis[51][51];
    int dfs(int a,int b,vector<vector<int>>&g){
        if(a<0||b<0||a>=g.size()||b>=g[0].size()) return 0;
        if(g[a][b]==0) return 0;
        if(vis[a][b]) return 0;
        vis[a][b]=1;
        int dx=dfs(a,b+1,g);
        int dy=dfs(a+1,b,g);
        int dxn=dfs(a,b-1,g);
        int dyn=dfs(a-1,b,g);
        return 1+dx+dy+dyn+dxn;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int res=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                
                if(!vis[i][j]&&g[i][j]!=0) {
                    int area=dfs(i,j,g);
                    //cout<<area<<endl;
                    res=max(area,res);
                }
            }
        }
        
        
        return res;
    }
};