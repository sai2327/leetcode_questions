class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        map<int,int>mp;
        mp[0] = -1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find(sum%k)!=mp.end()){
                int foundAt = mp[sum%k];
                if(i-foundAt>=2){
                    return true;
                }
            }
            else{
                mp[sum%k] = i;
            }
        }
        return false;
    }
};