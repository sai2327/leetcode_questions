class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long a=*max_element(nums.begin(),nums.end())-*min_element(nums.begin(),nums.end());
        return (long long)a*k;
    }
};