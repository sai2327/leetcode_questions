class Solution {
public:
    vector<vector<string>>res;
    bool check(vector<string>&board,int r,int c,int n){
        for(int i=0;i<r;i++){
            if(board[i][c]=='Q')return false;
        }
        for(int i=r-1,j=c-1;i>=0 and j>=0;i--,j--){
            if(board[i][j]=='Q')return false;
        }
        for(int i=r-1,j=c+1;i>=0 and j<n;i--,j++){
            if(board[i][j]=='Q')return false;
        }
        return true;
    }
    void rec(vector<string>&board,int r,int n){
        if(r==n){
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(check(board,r,i,n)){
                board[r][i]='Q';
                rec(board,r+1,n);
                board[r][i]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        rec(board,0,n);
        return res.size();    
    }
};
