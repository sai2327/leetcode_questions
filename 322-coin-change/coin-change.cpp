class Solution {
public:
    int mincoins(int amount,vector<int>&coins,vector<int>&dp){
        //base case
        if(amount==0) return 0;
        int ans=INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        for(int i:coins){
            if(amount-i>=0){
                int res=mincoins(amount-i,coins,dp);
                if(res!=INT_MAX)ans=min(ans,res+1);
            }
        }
        return dp[amount]=ans;
    }
    int coinChange( vector<int>& coins,int amount) {
        vector<int>dp(amount+1,-1);
        int ans=mincoins(amount,coins,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};