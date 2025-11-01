class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>mp;
        for(int i:nums) mp[i]++;
        int ans=0;
        for(auto [num,freq]:mp){
            if(mp.count(num+1)){
                ans=max(ans,mp[num+1]+freq);
            }
        }
        return ans;
    }
};