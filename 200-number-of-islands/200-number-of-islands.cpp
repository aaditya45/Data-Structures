class Solution {
public:
    
    void dfs(int a,int b,vector<vector<char>>& g){
        if(a<0||b<0||a>=g.size()||b>=g[0].size()){
            return;
        }
        if(g[a][b]=='0') return;
        g[a][b]='0';
        dfs(a+1,b,g);
        dfs(a-1,b,g);
        dfs(a,b+1,g);
        dfs(a,b-1,g);
        
    }
    
    
    int numIslands(vector<vector<char>>& g) {
        int res=0;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]=='1'){
                    res++;
                    dfs(i,j,g);
                }
                
            }
            
        }
        return res;
    }
};