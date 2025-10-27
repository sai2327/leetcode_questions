class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (auto& it : nums) {
            it = it * it;
        }
        sort(nums.begin(), nums.end());
        int c1;
        if (n % 2 == 0)
            c1 = n / 2;
        else
            c1 = n / 2 + 1;
        int cnt1 = 0;
        bool flag = true;
        long long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (cnt1 == c1) {
                flag = false;
            }
            if (flag)
                ans += nums[i];
            else
                ans -= nums[i];
            cnt1++;
        }
        return ans;
    }
};