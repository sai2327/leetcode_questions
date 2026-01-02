class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        // map<int,int>mpp;
        // int n=nums.size()/2;
        // for(int i=0;i<nums.size();i++){
        //     mpp[nums[i]]++;
        // } 
        // for(auto& i:mpp){
        //     if(i.second==n) return i.first;
        // }
        // return 0;
        for(int i=0;i<n-2;i++){//Loop in array, but stop at n-2
         //Check if current ele is same as next ele(consecutive duplicate) OR
          //check if current ele is same as ele 2 places ahead 
            if(nums[i]==nums[i+1]||nums[i]==nums[i+2]){
                return nums[i];
            }
        }
        return nums[n-1];
    }
};