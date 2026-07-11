class Solution {
public:
    void dfs1(int u,int parent,vector<vector<int>>&mat,vector<int>&res,vector<int>&cnt){
        cnt[u]=1;
        for(int v:mat[u]){
            if(v!=parent){
                dfs1(v,u,mat,res,cnt);
                cnt[u]+=cnt[v];
                res[u]+=res[v]+cnt[v];
            }
        }
    }
    void dfs2(int u,int parent,int n,vector<vector<int>>&mat,vector<int>&res,vector<int>&cnt){
        for(int v:mat[u]){
            if(v!=parent){
                res[v]=n+res[u]-2*cnt[v];
                dfs2(v,u,n,mat,res,cnt);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>mat(n);
        vector<int>cnt(n),res(n);
        for(auto& e:edges){
            mat[e[0]].push_back(e[1]);
            mat[e[1]].push_back(e[0]);
        }
        dfs1(0,-1,mat,res,cnt);
        dfs2(0,-1,n,mat,res,cnt);
        return res;
    }
};