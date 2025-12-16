class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res=0,sum=0;
        unordered_map<int,int>mp;
        int l=0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            mp[nums[r]]++;
            if(r-l+1>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                sum-=nums[l];
                l++;
            }
            if(mp.size()==k and (r-l+1)==k)res=max(res,sum);
        }
        return res;
    }
};