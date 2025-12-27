class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<long long,vector<long long>,greater<long long>>room;
        vector<long long >ans(n),end_time(n);
        for(int i=0;i<n;i++) room.push(i);
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>time_room;
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<meetings.size();i++){
            while(!time_room.empty() and time_room.top().first<=meetings[i][0]){
                room.push(time_room.top().second);
                time_room.pop();
            }
            if(room.empty()){
                room.push(time_room.top().second);
                time_room.pop();
            }
            if(!room.empty()){
                long long r=room.top();
                room.pop();
                ans[r]++;
                if(meetings[i][0]>=end_time[r]){
                    end_time[r]=meetings[i][1];
                    time_room.push({meetings[i][1],r});
                }
                else{
                    long long p=meetings[i][1]-meetings[i][0];
                    end_time[r]+=p;
                    time_room.push({end_time[r],r});
                }
            }
        }
        return max_element(ans.begin(),ans.end())-ans.begin();
    }
};