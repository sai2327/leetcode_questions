class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<long long>suff(n);
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=(long long)suff[i+1]*nums[i];
        }
        vector<int>ans;
        ans.push_back(suff[1]);
        long long pro=nums[0];
        for(int i=1;i<n-1;i++)
        {
            ans.push_back((long long)suff[i+1]*pro);
            pro*=nums[i];
        }
        ans.push_back(pro);
        return ans;
    }
};