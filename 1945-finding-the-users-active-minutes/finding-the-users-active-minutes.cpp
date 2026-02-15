class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,unordered_set<int>>mp;
        vector<int>res(k,0);
        for(auto &l:logs)mp[l[0]].insert(l[1]);
        for(auto &i:mp) res[i.second.size()-1]++;
        return res;
    }
};