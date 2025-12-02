class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int mod=1e9+7;
        unordered_map<int ,int>mp;
        for(auto i:points) mp[i[1]]++;
        long long sum=0,ans=0;
        for(auto i:mp){
            long long ncr=(long long)(i.second)*(i.second-1)/2;
            ans+=sum*ncr;
            ans%=mod;
            sum+=ncr;
            sum%=mod;
        }
        return ans;
    }
};