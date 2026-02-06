class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int j=0,res=0;
        for(int i=0;i<nums.size();i++){
        //    long long m=(long long) nums[j]*k;
            while((long long)nums[i]>(long long) nums[j]*k) j++;
            res=max(res,i-j+1);
        }
        return nums.size()-res;
    }
};