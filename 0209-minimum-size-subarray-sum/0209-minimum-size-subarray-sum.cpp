class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res=INT_MAX,l=0,r=0;
        long long sum=0;
        while(l<nums.size() and r<nums.size()){
            sum+=nums[r++];
            while(sum>=target){
                res=min(res,r-l);
                sum-=nums[l];
                l++;
            }
        }
        return res==INT_MAX? 0:res;
    }
};