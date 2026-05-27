class Solution {
public:
    int cnt=0;
    void dfs(int i,vector<vector<pair<int,int>>>&mat,vector<bool>&vis){
        vis[i]=true;
        for(auto& node:mat[i]){
            if(!vis[node.first] && node.second==1) cnt++;
            if(!vis[node.first])dfs(node.first,mat,vis);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>mat(n);
        for(auto& i:connections){
            mat[i[0]].push_back({i[1],1});
            mat[i[1]].push_back({i[0],0});
        }
        vector<bool>vis(n);
        dfs(0,mat,vis);
        return cnt;
    }
};