class Solution {
public:
    vector<int>parent;
    int findparent(int node){
        if(parent[node]==node)return node;
        return parent[node]=findparent(parent[node]);
    }
    bool dsu(int u,int v,vector<int>&rank){
        int paru=findparent(u);
        int parv=findparent(v);
        if(paru==parv)return false;
        if(rank[paru]<rank[parv]){
            parent[paru]=parv;
        }
        else if(rank[parv]<rank[paru]) parent[parv]=paru;
        else{
            rank[u]++;
            parent[parv]=paru;
        }
        return true;
    }
    int shortestpath(int src,int dest,int n,vector<vector<int>>&mat){
        vector<int>dis(n,-1);
        queue<int>q;
        q.push(src);
        dis[src]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(u==dest) return dis[u];
            for (int v:mat[u]) {
                if ((u==src && v==dest) || (u==dest && v==src)){
                    continue;
                }
                if(dis[v]==-1 or dis[v]>dis[u]+1){
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
        }
        return -1;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        vector<int>rank(n);
        for(int i=0;i<n;i++)parent[i]=i;
        vector<vector<int>>mat(n);
        int mini=1e9;
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            mat[u].push_back(v);
            mat[v].push_back(u);
            if(!dsu(u,v,rank)){
                int len=shortestpath(u,v,n,mat);
                if (len!=-1){
                    mini=min(mini,len+1);
                }
            }
        }
        
        if(mini==1e9) return -1;
        return mini;
    }
};