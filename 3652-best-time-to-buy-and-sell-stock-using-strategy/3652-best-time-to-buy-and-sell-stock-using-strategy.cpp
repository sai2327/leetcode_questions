class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long>p(n+1,0),p1(n+1,0);
        for(int i=0;i<n;i++){
            p[i+1]=p[i]+prices[i];
            p1[i+1]=p1[i]+1LL*prices[i]*strategy[i];
        }
        long long base = p1[n], maxi = base;
        for (int i = 0; i <= n-k; i++) {
            long long oldBlock = p1[i+k] - p1[i];
            long long newBlock = p[i+k] - p[i+k/2];
            long long total = base - oldBlock + newBlock;
            maxi = max(maxi, total);
        }
        return maxi;
    }
};