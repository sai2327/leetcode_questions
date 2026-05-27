class Solution {
public:
    int cnt=0;
    void dfs(int node,vector<vector<int>>&mat,vector<bool>&vis){
        if(!vis[node]){
            vis[node]=true;
            cnt++;
            for(auto& neigh:mat[node]){
                dfs(neigh,mat,vis);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>>mat(n);
        vector<bool>rest(n,false),vis(n,false);
        for(int i=0;i<restricted.size();i++)rest[restricted[i]]=true;
        for(auto& e:edges){
            int u=e[0],v=e[1];
            if(rest[u] or rest[v]) continue;
            mat[u].push_back(v);
            mat[v].push_back(u);
        }
        dfs(0,mat,vis);
        return cnt;
    }
};