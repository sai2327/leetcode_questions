class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1 and i>0 and j>0){
                    matrix[i][j]=1+min({matrix[i][j-1],matrix[i-1][j],matrix[i-1][j-1]});
                }
                res+=matrix[i][j];
            }
        }
        return res;
    }
};