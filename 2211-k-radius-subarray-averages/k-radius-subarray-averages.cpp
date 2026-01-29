class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size(),winsize=2*k+1;
        vector<int>res(n,-1);
        if(n<winsize) return res;
        vector<long long>prefsum(n+1,0);
        for(int i=0;i<n;i++){
            prefsum[i+1]=prefsum[i]+nums[i];
        }
        for(int i=k;i<n-k;i++) res[i]=(prefsum[i+k+1]-prefsum[i-k])/winsize;
        return res;
    }
};