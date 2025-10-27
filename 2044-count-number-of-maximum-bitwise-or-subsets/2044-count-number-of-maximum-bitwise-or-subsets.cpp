class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0, count = 0;
        for (int num : nums)
            maxOr |= num;
        int total = 1 << n;
        for (int mask = 0; mask < total; mask++) {
            int currOr = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i))
                    currOr |= nums[i];
            }
            if (currOr == maxOr)
                count++;
        }
        return count;
    }
};