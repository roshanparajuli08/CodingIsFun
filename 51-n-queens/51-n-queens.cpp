class Solution {
    public:
    bool checkOk(int row, int col, vector<string> board, int n){
        //left_chekck
        int left_row = row;
        int left_col = col;
        while(left_col >= 0){
            if( board[left_row][left_col] == 'Q')
                return false;
            left_col--;
        }
        
        //leftupdiagonal
        int duprow = row;
        int dupcol = col;
        while(duprow>=0 && dupcol >= 0)
        {
         if(board[duprow][dupcol]== 'Q') return false;
        duprow--;
        dupcol--;
        }
        
        //diagonal_down
        int ddownrow = row;
        int ddowncol = col;
        while(ddownrow<n && ddowncol >= 0) 
        {
            if(board[ddownrow][ddowncol]== 'Q') 
                return false;
            ddownrow++;
            ddowncol--; 
        }
        return true;
    }
    public:
    void queenRecurr(int col, vector<vector<string>> &ans, vector<string>& board, int n){
        //base_case
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        //recurr_caase
        for(int row = 0; row<n; row++){
            if(checkOk(row, col, board, n)){
                board[row][col] = 'Q';
                queenRecurr(col+1, ans, board, n);
                board[row][col] = '.';
            }
        }
        
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        int col = 0;
        string s(n, '.');
            for(int i=0; i<n; i++){
                board[i] = s;
            }
        queenRecurr(col, ans, board, n);
        return ans;
  
}
};