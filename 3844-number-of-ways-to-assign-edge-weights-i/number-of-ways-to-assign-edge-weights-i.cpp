class Solution {
public:
    int mod=1e9+7;
    int max_depth;
    void dfs(int node, int parent, int curr,vector<vector<int>>& mat) {
        max_depth=max(max_depth,curr);
        for (int neigh:mat[node]){
            if (neigh!=parent){
                dfs(neigh,node,curr+1,mat);
            }
        }
    }
    long long power(long long base,long  long exp){
        if(exp==0) return 1;
        if(exp&1){
            return (base*power(base,exp-1)%mod)%mod;;
        }
        return power((base*base)%mod,exp/2)%mod;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>mat(n+1);
        for(auto& edge : edges) {
            mat[edge[0]].push_back(edge[1]);
            mat[edge[1]].push_back(edge[0]);
        }
        max_depth=0;
        dfs(1,0,0,mat);
        if (max_depth==0) return 0;
        return power(2,max_depth - 1);
    }
};