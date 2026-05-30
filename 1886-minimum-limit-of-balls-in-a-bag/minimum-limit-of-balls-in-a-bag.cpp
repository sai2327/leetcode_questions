class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOps) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<high){
            int mid=(low+high)/2;
            int ops=0;
            for(int i:nums){
                ops+=(i-1)/mid;
            }
            if(ops>maxOps)low=mid+1;
            else high=mid;
        }
        return high;
    }
};