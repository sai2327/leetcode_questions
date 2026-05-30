class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=0,high=0;
        for(int i=0;i<nums.size();i++){
            low=max(nums[i],low);
            high+=nums[i];
        }
        while(low<high){
            int mid=(low+high)/2,sum=0,chunks=1;
            for(int i:nums){
                if(sum+i>mid){
                    chunks++;
                    sum=i;
                }
                else sum+=i;
            }
            if(chunks>k) low=mid+1;
            else high=mid;
        }
        return high;
    }
};