class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<int>>res;
        for(int i:nums1)pq.push({i+nums2[0],0});
        while(k-- and !pq.empty()){
            int sum=pq.top().first,pos=pq.top().second;
            res.push_back({sum-nums2[pos],nums2[pos]});
            pq.pop();
            if(pos+1<nums2.size()){
                pq.push({sum-nums2[pos]+nums2[pos+1],pos+1});
            }
        }
        return res;
    }
};