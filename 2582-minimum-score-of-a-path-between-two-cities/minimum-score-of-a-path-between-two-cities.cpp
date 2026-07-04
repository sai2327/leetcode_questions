class Solution {
public:
    int find(int node,vector<int>&parent){
        if(parent[node]!=node)parent[node]=find(parent[node],parent);
        return parent[node];
    }
    void unionfind(int a,int b,vector<int>&parent,vector<int>&rank){
        int pa=find(a,parent),pb=find(b,parent);
        if(pa==pb) return ;
        if(rank[pa]<rank[pb]) parent[pa]=pb;
        else if(rank[pa]>rank[pb]) parent[pb]=pa;
        else{
            parent[pb]=pa;
            rank[pa]++;
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int>parent(n+1),rank(n+1);
        for(int i=1;i<=n;i++) parent[i]=i;
        for(auto &e:roads){
            unionfind(e[0],e[1],parent,rank);
        }
        int res=INT_MAX;
        int val=find(1,parent);
        for(auto &e:roads){
            if(find(e[0],parent)==val)res=min(res,e[2]);
        }
        return res;
    }
};