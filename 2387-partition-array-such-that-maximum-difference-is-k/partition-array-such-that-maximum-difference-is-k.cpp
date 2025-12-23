class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,cnt=1;
        for(int r=0;r<nums.size();r++){
            int diff = nums[r]-nums[l];
            if(diff>k){
                l = r;
                cnt++;
            }
        }
        return cnt;
    }
};