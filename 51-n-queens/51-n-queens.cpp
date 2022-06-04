class Solution {
public:
    bool is_safe(int row ,int col , vector<vector<int>>&board){
        for(int i =0 ;i<col;i++){
            if(board[row][i] == 1) return false;
        }
        int _row = row;
        int _col = col;
        while(_row>=0 && _col>=0){
            if(board[_row][_col] == 1) return false;
            _row--;
            _col--;
        }
        _row = row;
        _col = col;
        while(_row<board.size() && _col>=0){
            if(board[_row][_col] == 1) return false;
            _row++;
            _col--;
        }
        return true;
    }
    void func(int col, int N , vector<string>&ds , vector<vector<int>>&board, vector<vector<string>>&ans){
        if(col == N){
            ans.push_back(ds);
            return;
        }
        for(int row =0 ;row<N;row++){
            if(is_safe(row,col,board)){
                board[row][col] = 1;
                string model = "";
                for(int i = 0 ;i<N;i++){
                    if(i == row) model.push_back('Q');
                    else model.push_back('.');
                }
                ds.push_back(model);
                func(col+1,N,ds,board,ans);
                board[row][col] = 0;
                ds.erase(ds.end()-1);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<vector<string>> ans;
        vector<string> ds;
        func(0,n,ds,board,ans);
        return ans;
    }
};