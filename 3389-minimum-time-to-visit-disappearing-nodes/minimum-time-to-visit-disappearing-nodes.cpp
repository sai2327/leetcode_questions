class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear){
        vector<vector<pair<int,int>>>mat(n);
        for(auto& edge:edges){
            mat[edge[0]].push_back({edge[1],edge[2]});
            mat[edge[1]].push_back({edge[0],edge[2]});
        }
        vector<int>dis(n,INT_MAX);
        dis[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<bool>vis(n,false);
        
        while(!pq.empty()){
            int wt=pq.top().first,next=pq.top().second;
            pq.pop();
            if(vis[next])continue;
            vis[next]=true;

            for(auto& u:mat[next]){
                if(wt+u.second<dis[u.first]){
                    if(disappear[u.first]>wt+u.second){
                        dis[u.first]=wt+u.second;
                        pq.push({dis[u.first],u.first});
                    }
                }
            }
        }
        for(int i=0;i<n;i++) if(dis[i]==INT_MAX) dis[i]=-1;
        return dis;
    }
};