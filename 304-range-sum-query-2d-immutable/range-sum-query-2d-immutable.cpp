class NumMatrix {
public:
    int row,col;
    vector<vector<int>>pref;
    NumMatrix(vector<vector<int>>& matrix) {
        row=matrix.size();
        if(row>0)col=matrix[0].size();
        else col=0;
        pref=vector<vector<int>>(row+1,vector<int>(col+1,0));
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                pref[i][j]=matrix[i-1][j-1]+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pref[row2+1][col2+1]-pref[row2+1][col1]-pref[row1][col2+1]+pref[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */