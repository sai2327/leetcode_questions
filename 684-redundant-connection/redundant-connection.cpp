class Solution {
public:
    int findparent(int node,vector<int>&par){
        if(par[node]==node)return node;
        return par[node]=findparent(par[node],par);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>>mat(edges.size()+1);
        int n=edges.size();
        vector<int>par(n+1),rank(n+1,0);
        for(int i=1;i<=n;i++){
            par[i]=i;
        }
        for(auto &e:edges){
            int u=e[0],v=e[1];
            int paru=findparent(u,par);
            int parv=findparent(v,par);
            if(paru==parv) return{u,v};
            if(rank[paru]<rank[parv])par[paru]=parv;
            else if(rank[parv]<rank[paru])par[parv]=paru;
            else {
                rank[u]++;
                par[parv]=paru;
            }
        }
        return {};
    }
};