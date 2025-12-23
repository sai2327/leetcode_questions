class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
    int atmost(vector<int>&nums,int goal){
        if(goal<0) return 0;
        int l=0,cnt=0,res=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]==1)cnt++;
            while(cnt>goal){
                if(l<nums.size() and nums[l]==1){
                    cnt--;
                }
                l++;
            }
            res+=r-l+1;
        }
        return res;
    }
};