class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,int>>q;
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        q.push({src,0});
        vector<vector<pair<int,int>>>mat(n);
        for(auto &e:flights){
            mat[e[0]].push_back({e[1],e[2]});
        }
        int cnt=0;
        while(!q.empty() and cnt<=k){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto u=q.front();
                q.pop();
                for(auto& neigh:mat[u.first]){
                    int v=neigh.first,wt=neigh.second;
                    if(u.second+wt<dis[v]){
                        dis[v]=wt+u.second;
                        q.push({v,dis[v]});
                    }
                }
            }
            cnt++;
        }
        if(dis[dst]==INT_MAX) return -1;
        return dis[dst];
    }
};