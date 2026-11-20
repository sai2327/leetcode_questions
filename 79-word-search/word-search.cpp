class Solution {
public:
    bool dfs(vector<vector<char>>&board,string &word,int i,int j,int idx){
        if(idx==word.size())return true;
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]!=word[idx])return false;
        char c=board[i][j];
        board[i][j]='!';
        bool flag=dfs(board,word,i+1,j,idx+1) or dfs(board,word,i-1,j,idx+1) or dfs(board,word,i,j+1,idx+1) or dfs(board,word,i,j-1,idx+1);
        board[i][j]=c;
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j])if(dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};