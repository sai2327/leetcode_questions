class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>pref(n+1,0);
        for(int i=0;i<n;i++) pref[i+1]=pref[i]+nums[i];
        deque<int>dq;
        int ans=n+1;
        for(int i=0;i<=n;i++){
            while(!dq.empty() and pref[i]<=pref[dq.back()]){
                dq.pop_back();
            }
            while(!dq.empty() and pref[i]-pref[dq.front()]>=k){
                ans=min(ans,i-dq.front());
                dq.pop_front();
            }
            dq.push_back(i);
        }
        if(ans==n+1) return -1;
        return ans;
    }
};