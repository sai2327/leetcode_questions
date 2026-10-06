class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        int cnt=min(m,n)/2;
        for(int i=0;i<cnt;i++){
            vector<int>temp;
            int t=i,l=i,b=n-i-1,r=m-i-1;
            for(int j=l;j<=r;j++) temp.push_back(grid[t][j]);
            for(int j=t+1;j<=b-1;j++)temp.push_back(grid[j][r]);
            for(int j=r;j>=l;j--) temp.push_back(grid[b][j]);
            for(int j=b-1;j>=t+1;j--) temp.push_back(grid[j][l]);
            int sz=temp.size();
            int x=k%sz;
            vector<int>v;
            for(int j=x;j<sz;j++) v.push_back(temp[j]);
            for(int j=0;j<x;j++) v.push_back(temp[j]);
            int idx=0;
            for(int j=l;j<=r;j++){
                grid[t][j]=v[idx++];
                if(idx==sz)idx=0;
            }
            for(int j=t+1;j<=b-1;j++){
                grid[j][r]=v[idx++];
                if(idx==sz)idx=0;
            }
            for(int j=r;j>=l;j--){
                grid[b][j]=v[idx++];
                if(idx==sz)idx=0;
            }
            for(int j=b-1;j>=t+1;j--){
                grid[j][l]=v[idx++];
                if(idx==sz)idx=0;
            }
        }
        return grid;
    }
};