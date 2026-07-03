class Solution {
public:
    bool Dijkstras(vector<vector<pair<int,int>>>& mat,int n,long long key,long long k){
        vector<long long>Dis(n,LLONG_MAX);
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        Dis[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            long long wt=pq.top().first;
            long long u=pq.top().second;pq.pop();
            for(pair<int,int>&p:mat[u]){
                int v=p.first;
                long long cost=p.second;
                if(cost>=key && Dis[v]>wt+cost){
                    Dis[v]=wt+cost;
                    pq.push({Dis[v],v});
                }
            }
        }
        return Dis[n-1]<=k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<pair<int,int>>>mat(n);
        for(vector<int>& e:edges)if(online[e[0]] && online[e[1]])mat[e[0]].push_back({e[1],e[2]});
        long long low=1,high=1e9;
        if(!Dijkstras(mat,n,0,k))return -1;
        while(low<=high){
            long long mid=(low+high)>>1;
            if(Dijkstras(mat,n,mid,k))low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};