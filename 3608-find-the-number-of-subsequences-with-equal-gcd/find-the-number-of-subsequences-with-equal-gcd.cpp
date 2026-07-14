class Solution {
public:
    int dp[201][201][201];
    int mod=1e9+7;
    int rec(vector<int>& nums,int i,int gcd1,int gcd2){
        long long ans=0;
        if(i>=nums.size()){
            if(gcd1>=1 and gcd1==gcd2) {
                return 1;
            }
            return 0;
        }
        if(dp[i][gcd1][gcd2]!=-1) return dp[i][gcd1][gcd2];
        ans+=(1LL * rec(nums,i+1,gcd1,gcd2))%mod;
        ans+=(1LL * rec(nums,i+1,gcd(gcd1,nums[i]),gcd2))%mod;
        ans+=(1LL * rec(nums,i+1,gcd1,gcd(gcd2,nums[i])))%mod;
        return dp[i][gcd1][gcd2]=ans%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return rec(nums,0,0,0);
    }
};