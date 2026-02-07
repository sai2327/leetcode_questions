class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        vector<int>prefup(nums.size(),1);
        vector<int>prefdown(nums.size(),1);
        vector<int>suffup(nums.size(),1),suffdown(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]) prefdown[i]+=prefup[i-1];
            if(nums[i]>nums[i-1]) prefup[i]+=prefdown[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>nums[i+1]) suffup[i]+=suffdown[i+1];
            if(nums[i]<nums[i+1]) suffdown[i]+=suffup[i+1];
        }
        int res=0;
        for(int i=0;i<nums.size();i++)
            res = max(res, max(prefup[i], prefdown[i]));
        
        int n=nums.size();
        for(int i=1;i<n-1;i++){
            if (nums[i - 1] < nums[i + 1]) {
                res = max(res, prefdown[i - 1] + suffup[i + 1]);
            }
            if (nums[i - 1] > nums[i + 1]) {
                res = max(res, prefup[i - 1] + suffdown[i + 1]);
            }
        }
        return res;
    }
};