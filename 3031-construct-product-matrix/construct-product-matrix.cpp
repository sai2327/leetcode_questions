class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    int n=grid.size(),m=grid[0].size(),mod=12345,product=1;
    vector<vector<int>>p(n,vector<int>(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m; j++) {
            p[i][j]=product;
            product=(product*(grid[i][j]%mod))%mod;
        }
    }
    product = 1;
    for(int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            p[i][j] = (p[i][j] * product) % mod;
            product = (product * (grid[i][j] % mod)) %mod;
        }
    }
    return p;
    }
};