class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long mini=nums[0],maxi=nums[0],best=nums[0];
        for(int i=1;i<nums.size();i++){
            long long a=1LL*nums[i]*mini;
            long long b=1LL*nums[i]*maxi;
            mini=min({1LL*nums[i],b,a});
            maxi=max({1LL*nums[i],a,b});
            best=max(maxi,best);
        }
        return best;
    }
};