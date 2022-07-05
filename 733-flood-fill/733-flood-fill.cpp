class Solution {
public:
    
    void dfs( int a, int b,int nc,vector<vector<int>>& im,int val){
        if(a<0||b<0||a>=im.size()||b>=im[0].size()) return;
        if(im[a][b]!=val) return;
        im[a][b]=nc;
        dfs(a+1,b,nc,im,val);
        dfs(a-1,b,nc,im,val);
        dfs(a,b+1,nc,im,val);
        dfs(a,b-1,nc,im,val);
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int val=image[sr][sc];
        if(val==newColor) return image;
        dfs(sr,sc,newColor,image,val);
        return image;
    }
};