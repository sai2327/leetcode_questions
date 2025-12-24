class Solution {
public:
    
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        dp[nums.size()-1]=0;
        for(int i=nums.size()-2;i>=0;i--){
            int mini=1e9;
            if(nums[i]+i>=nums.size()){
                dp[i]=1;
                continue;
            }
            for(int j=i+1;j<nums.size() and j<=i+nums[i];j++){
                mini=min(dp[j],mini);
            }
            dp[i]=mini+1;
        }
        return dp[0];
    }
};