class Solution {
public:
    int minElement(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int m=nums[i],sum=0;
            while(m){
                int r=m%10;
                sum+=r;
                m/=10;
            }
            nums[i]=sum;
        }
        int mini=*min_element(nums.begin(),nums.end());
        return mini;
    }
};