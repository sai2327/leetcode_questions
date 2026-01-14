class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<long long>dp(4,-1e11);
        for(int bi:b){
            for(int i=3;i>=0;i--){
                long long n=(i>0 ? dp[i-1]:0LL)+1LL*a[i]*bi;
                dp[i]=max(dp[i],n);
            }
        }
        return dp[3];
    }
};