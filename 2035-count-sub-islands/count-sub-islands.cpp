class Solution {
public:
    int m,n;
    int dfs(vector<vector<int>>&grid1,vector<vector<int>>&grid2,int i,int j){
        if(i<0 || i>=m || j<0 || j>=n || grid2[i][j]==0) {
            return true;
        }
        grid2[i][j]=0;
        bool isSubIsland=true;
        if (grid1[i][j]==0){
            isSubIsland=false;
        }
        isSubIsland&=dfs(grid1, grid2,i+1,j);
        isSubIsland&=dfs(grid1, grid2,i-1,j);
        isSubIsland&=dfs(grid1, grid2,i,j+1);
        isSubIsland&=dfs(grid1, grid2,i,j-1);        
        return isSubIsland;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m=grid2.size();
        n=grid2[0].size();
        int cnt=0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid2[i][j] == 1){
                    if (dfs(grid1, grid2, i, j)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};