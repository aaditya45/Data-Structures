class Solution {
public:
    int dir[5]={0,1,0,-1,0};
    void distinct(pair<int,int> o,vector<vector<int>>&grid,queue<pair<int,int>>&q){
        if(o.first>=grid.size()||o.second>=grid[0].size()||o.first<0||o.second<0) return;
        if(grid[o.first][o.second]==0||grid[o.first][o.second]==2) return;
        grid[o.first][o.second]=2;
        q.push({o.first,o.second});
        for(int d=0;d<4;d++) distinct({o.first+dir[d],o.second+dir[d+1]},grid,q);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        pair<int,int> o={-1,-1};
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) {o={i,j};break;}
            }
            if(o!=make_pair(-1,-1)) break;
        }
        queue<pair<int,int>> q;
        distinct(o,grid,q);
        int res=INT_MAX;
        vector<vector<int>> vis(n,vector<int>(m,0));
        while(!q.empty()){
            int vol=q.size();
            while(vol--){
                int a=q.front().first;
                int b=q.front().second;
                q.pop();
                for(int d=0;d<4;d++){
                    int x=a+dir[d],y=b+dir[d+1];
                    if(min(x,y)>=0&&x<n&&y<m){
                        if(grid[x][y]==1){
                            return grid[a][b]-2;
                        }
                        if(grid[x][y]==0){
                            grid[x][y]=grid[a][b]+1;
                            q.push({x,y});
                        }
                    }
                }
            }
        }
        return 0;
    }
};