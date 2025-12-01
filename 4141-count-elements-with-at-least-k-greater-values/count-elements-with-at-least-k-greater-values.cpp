class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int cnt = n - (upper_bound(nums.begin(), nums.end(), nums[i]) - nums.begin());
            if(cnt >= k) ans++;
        }
        return ans;
    }
};