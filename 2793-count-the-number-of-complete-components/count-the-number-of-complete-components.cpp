class Solution {
public:
    void dfs(int node,vector<vector<int>>&mat,vector<bool>&vis,int &cntn,int &cntd){
        vis[node]=true;
        cntn++;
        cntd+=mat[node].size();
        for(int i:mat[node]){
            if(!vis[i]){
                dfs(i,mat,vis,cntn,cntd);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>mat(n);
        for(auto& edge:edges){
            mat[edge[0]].push_back(edge[1]);
            mat[edge[1]].push_back(edge[0]);
        }
        int res=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int cntn=0,cntd=0;
                dfs(i,mat,vis,cntn,cntd);
                if(cntn*(cntn-1)==cntd)res++;
            }
        }
        return res;
    }
};