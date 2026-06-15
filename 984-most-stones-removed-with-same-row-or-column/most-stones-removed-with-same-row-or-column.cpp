class Solution {
public:
    int findparent(int node,vector<int>&par){
        if(par[node]==node) return node;
        return par[node]=findparent(par[node],par);
    }
    void unionfind(int u,int v,vector<int>&par,vector<int>&rank){
        int paru=findparent(u,par);
        int parv=findparent(v,par);
        if(paru!=parv){
            if(rank[paru]<rank[parv]){
                par[paru]=parv;
            }
            else if(rank[parv]<rank[paru])par[parv]=paru;
            else {
                rank[u]++;
                par[parv]=paru;
            }
        }        
    }
    int removeStones(vector<vector<int>>& stones) {
        vector<int>par(stones.size()),rank(stones.size(),0);
        for(int i=0;i<stones.size();i++)par[i]=i;
        unordered_map<int,int>lastrow,lastcol;
        for(int i=0;i<stones.size();i++){
            int r=stones[i][0],c=stones[i][1];
            if(lastrow.count(r)){
                unionfind(i,lastrow[r], par, rank);
            }
            else{
                lastrow[r]=i;
            }
            if(lastcol.count(c)){
                unionfind(i,lastcol[c], par, rank);
            } 
            else{
                lastcol[c]=i;
            }
        }
        int cnt=0;
        for(int i=0;i<par.size();i++)if(par[i]==i) cnt++;
        return stones.size()-cnt;
    }
};