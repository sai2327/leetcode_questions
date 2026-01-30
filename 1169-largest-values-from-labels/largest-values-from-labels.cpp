class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n=values.size();
        map<int,int>mp;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({values[i],labels[i]});
        }
        int sum=0,cnt=0;
        while(cnt<numWanted && pq.size()!=0){
            auto it=pq.top();
            pq.pop();
            int value=it.first;
            int label=it.second;
            if(mp[label]<useLimit){
                sum+=value;
                mp[label]++;
                cnt++;
            }
        }
        return sum;
    }
};