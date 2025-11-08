class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int> prefix{{0 , -1}};
        int res = 0, last = -1, curr = 0;
        for(int i = 0, n = nums.size(); i < n; ++i){
            curr += nums[i];
            if(prefix.count(curr - target) && last <= prefix[curr - target]){
                last = i;
                ++res;
            }
            prefix[curr] = i;
        }
        return res;
    }
};