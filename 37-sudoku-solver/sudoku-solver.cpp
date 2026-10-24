class Solution {
public:
    bool isvalid(vector<vector<char>>&board,int I,int J,char num){
        for(int i=0;i<9;i++){
            if(board[I][i]==num)return false;
            if(board[i][J]==num)return false;
            int a=3*(I/3)+i/3,b=3*(J/3)+i%3;
            if(board[a][b]==num)return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char num='1';num<='9';num++){
                        if(isvalid(board,i,j,num)){
                            board[i][j]=num;
                            if(solve(board))return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>&board){
        solve(board);
    }
};