class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums[0],nums[(int)nums.size()-1]);
    }
};