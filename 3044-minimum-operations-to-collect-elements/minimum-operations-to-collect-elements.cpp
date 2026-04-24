class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int i=nums.size()-1;
        vector<int>cnt(51);
        for (int res=0;res<k;i--)
            if (nums[i]<=k)
                res+=cnt[nums[i]]++==0;
        return nums.size()-i-1;
    }
};