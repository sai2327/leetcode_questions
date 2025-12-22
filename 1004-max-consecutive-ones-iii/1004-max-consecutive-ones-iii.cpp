class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,window=0,zero=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]!=1) zero++;
            if(zero>k){
                if(nums[left]==0) zero--;
                left++;
            }
            window=max(r-left+1,window);
        }
        return window;
    }
};