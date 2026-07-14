class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            int col=i;
            bool flag=false;
            for(int j=0;j<m;j++){
                int d=grid[j][col];
                int ncol=col+d; 
                if (ncol<0 or ncol>=n or grid[j][col]!=grid[j][ncol]) {
                    flag=true;
                    break;
                }
                col=ncol;
            }
            if(flag) res[i]=-1;
            else res[i]=col;
        }
        return res;
    }
};
