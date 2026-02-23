class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        // for(auto i:intervals){
        //     cout<< i[0]<<"-"<<i[1]<<"🥺";
        // }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:intervals){
            if(!pq.empty() and pq.top() < i[0]) pq.pop();
            pq.push(i[1]);
        }
        // while(!pq.empty()){
        //     cout<<"👋"<<pq.top();
        //     pq.pop();
        // }
        return pq.size();
    }
};