class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size(),res=0;
        vector<int>dis(n,1e9);
        vector<bool>vis(n,false);
        dis[0]=0;
        for(int i=0;i<n;i++){
            int u=-1;
            for(int j=0;j<n;j++){
                if(!vis[j] and (u==-1 or dis[j]<dis[u])) u=j;
            }
            vis[u]=true;
            res+=dis[u];
            for(int v=0;v<n;v++){
                if(!vis[v])dis[v]=min(dis[v],abs(points[u][0]-points[v][0])+abs(points[u][1]-points[v][1]));
            }
        }
        return res;
    }
};