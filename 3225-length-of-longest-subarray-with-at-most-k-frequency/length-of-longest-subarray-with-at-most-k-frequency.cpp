class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0,n=nums.size(),res=1,left=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int num=nums[i];
            mp[num]++;
            while(mp[num]>k){
                mp[nums[left]]--;
                left++;
            }
            res=max(res,i-left+1);
        }
        return res;
    }
};

