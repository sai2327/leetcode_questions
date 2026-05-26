class Solution {
public:
    void dfs(int node,int distanceThreshold,vector<vector<pair<int,int>>>&mat,vector<int>&mindis){
        if(distanceThreshold<mindis[node]) return;
        mindis[node]=distanceThreshold;
        for(auto& i:mat[node]){
            int next=i.first,wt=i.second;
            if(distanceThreshold>=wt)
                if(distanceThreshold-wt>=mindis[next])
                    dfs(next,distanceThreshold-wt,mat,mindis);
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold){
        vector<vector<pair<int,int>>>mat(n);
        for(auto& edge:edges){
            mat[edge[0]].push_back({edge[1],edge[2]});
            mat[edge[1]].push_back({edge[0],edge[2]});
        }
        int res=0,mini=INT_MAX;
        for(int i=0;i<n;i++){
            vector<int>mindis(n,-1);
            dfs(i,distanceThreshold,mat,mindis);
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i!=j and mindis[j]!=-1) cnt++;
            }
            if(cnt<=mini){
                mini=cnt;
                res=i;
            }
        }
        return res;
    }
};