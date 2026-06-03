class Solution {
public:
    void dfs(vector<vector<int>>&mat,vector<bool>&vis,int node,int &cnt){
        vis[node]=true;
        cnt++;
        for(auto v:mat[node]){
            if(!vis[v])dfs(mat,vis,v,cnt);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>mat(n);
        for(auto& e:edges){
            mat[e[0]].push_back(e[1]);
            mat[e[1]].push_back(e[0]);
        }
        long long res=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            long long non_reach=0,reachable=0;
            if(!vis[i]){
                int connectedcnt=0;
                dfs(mat,vis,i,connectedcnt);
                reachable+=connectedcnt;
                non_reach=n-reachable;
            }
            res+=reachable*non_reach;
        }
        return res/2;
    }
};