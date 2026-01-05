class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0,mini=LLONG_MAX,cnt=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]<0) cnt++;
                sum+=abs(matrix[i][j]);
                mini=min(mini,abs(1LL*matrix[i][j]));
            }
        }
        if(cnt%2==0)return sum;
        return sum-2*mini;
    }
    
};