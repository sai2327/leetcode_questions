class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        if(n==3) return nums[0]+nums[1]+nums[2];
        int a=INT_MAX,b=INT_MAX;
        for(int i=1;i<n;i++){
            int x=nums[i];
            if(x<a)b=exchange(a,x);
            else if(x<b)b=x;
        }
        return nums[0]+a+b;
    }
};