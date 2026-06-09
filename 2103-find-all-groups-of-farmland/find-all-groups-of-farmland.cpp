class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    int r = i;
                    int c = j;
                    while (r < m && land[r][j] == 1)r++;
                    while (c < n && land[i][c] == 1)c++;
                    res.push_back({i, j, r - 1, c - 1});
                    for (int x = i; x < r; x++) {
                        for (int y = j; y < c; y++) {
                            land[x][y] = 0;
                        }
                    }
                }
            }
        }
        return res;
    }
};