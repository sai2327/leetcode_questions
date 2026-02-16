class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>res;
        for(int n:nums){
            mp[n]++;
        }
        for(auto i:mp){
            if(i.second==1 and mp.count(i.first+1)==0 and mp.count(i.first-1)==0)res.push_back(i.first);
        }
        return res;
    }
};