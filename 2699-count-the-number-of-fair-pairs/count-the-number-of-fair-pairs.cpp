class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
            sort(nums.begin(),nums.end());
            for (int i=0;i+1<nums.size();i++){
                int mini=lower-nums[i],maxi=upper-nums[i];
                auto high=upper_bound(nums.begin()+i+1,nums.end(),maxi);
                auto low=lower_bound(nums.begin()+i+1,nums.end(),mini);
                ans+=(high-low);
            }
            return ans;
    }
};