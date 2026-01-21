class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==2)res.push_back(-1);
            else res.push_back(nums[i] - ((nums[i]+1) & -(nums[i]+1))/2);
        }
        return res;
    }
};