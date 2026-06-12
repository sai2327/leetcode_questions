class Solution {
public:
    int mod=1e9+7;
    vector<int> binaryexponent;
    vector<vector<int>> ancestors;
    vector<int> parent;
    vector<int> depth;
    vector<int> ans;
    void dfs(int node,int par,vector<vector<int>>& adj,int depthvalue){
        parent[node]=par;
        depth[node]=depthvalue;
        for(int child:adj[node]){
            if(child==par)continue;
            dfs(child,node,adj,depthvalue+1);
        }
    }
    void buildancestors(int n){
        int maxlog=18;
        ancestors.assign(maxlog,vector<int>(n+1));
        for(int node=1;node<=n;node++){
            ancestors[0][node]=parent[node];
        }
        for(int jump=1;jump<maxlog;jump++){
            for(int node=1;node<=n;node++){
                ancestors[jump][node]=ancestors[jump-1][ancestors[jump-1][node]];
            }
        }
    }
    int lca(int u,int v){
        if(depth[u]<depth[v])swap(u,v);

        int diff=depth[u]-depth[v];
        for(int bit=0;diff>0;bit++){
            if(diff&1)u=ancestors[bit][u];
            diff>>=1;
        }
        if(u==v)return u;
        for(int jump=ancestors.size()-1;jump>=0;jump--){
            if(ancestors[jump][u]!=ancestors[jump][v]){
                u=ancestors[jump][u];
                v=ancestors[jump][v];
            }
        }
        return ancestors[0][u];
    }
    int getpathlength(int u,int v){
        int lc=lca(u,v);
        return depth[u]+depth[v]-2*depth[lc];
    }
    vector<int>assignEdgeWeights(vector<vector<int>>& edges,vector<vector<int>>& queries){
        int n=edges.size()+1;
        int q=queries.size();
        binaryexponent.resize(n+1);
        binaryexponent[0]=1;
        for(int i=1;i<=n;i++){
            binaryexponent[i]=(2ll*binaryexponent[i-1])%mod;
        }
        parent.assign(n+1,0);
        depth.assign(n+1,0);
        ans.resize(q);
        vector<vector<int>> adj(n+1);
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,1,adj,0);
        buildancestors(n);
        for(int i=0;i<q;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            int pathlength=getpathlength(u,v);
            if(pathlength==0)ans[i]=0;
            else ans[i]=binaryexponent[pathlength-1];
        }
        return ans;
    }
};