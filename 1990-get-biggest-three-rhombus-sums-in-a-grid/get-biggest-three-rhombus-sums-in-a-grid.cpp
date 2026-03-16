class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int>res;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                res.insert(grid[i][j]);
                int k=1;
                while(true){
                    if(i-k<0 or i+k>=grid.size() or j-k<0 or j+k>=grid[0].size()) break;
                    int sum=0,r=i-k,c=j;
                    for(int l=0;l<k;l++) sum+=grid[r+l][c+l];
                    r=i;
                    c=j+k;
                    for(int l=0;l<k;l++) sum+=grid[r+l][c-l];
                    r=i+k;
                    c=j;
                    for(int l=0;l<k;l++) sum+=grid[r-l][c-l];
                    r=i;
                    c=j-k;
                    for(int l=0;l<k;l++) sum+=grid[r-l][c+l];
                    res.insert(sum);
                    k++;
                }
            }
        }
        vector<int>ans;
        int it=0;
        for(auto i=res.rbegin() ;i!=res.rend();i++){
            ans.push_back(*i);
            it++;
            if(it==3) break;
            
        }
        return ans;
    }
};