class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zero=false;
        for(int r=0;r<matrix.size();r++){
            if(matrix[r][0]==0) zero=true;
            for(int c=1;c<matrix[0].size();c++){
                if (matrix[r][c]==0){
                    matrix[r][0]=0;
                    matrix[0][c]=0;
                }
            }
        }
        for(int r=matrix.size()-1;r>=0;r--){
            for(int c=matrix[0].size()-1;c>=1;c--){
                if (matrix[r][0] == 0 || matrix[0][c] == 0) {
                    matrix[r][c]=0;
                }
            }
            if(zero){
                matrix[r][0] = 0;
            }
        }
    }
};