class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int cnt=0,col=grid[0].size();
        if(grid[0][0]>k) return 0;
        cnt++;
        for(int j=1;j<grid[0].size();j++){
            grid[0][j]+=grid[0][j-1];
            if(grid[0][j]>k){
                col=j;
                break;
            }
            cnt++;
        }
        for(int i=1;i<grid.size();i++){
            grid[i][0]+=grid[i-1][0];
            if(grid[i][0]>k) break;
            cnt++;
            for(int j=1;j<col;j++){
                grid[i][j]+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
                if(grid[i][j]>k) {
                    col=j;
                    break;
                }
                cnt++;
            }
        }
        return cnt;
    }
};