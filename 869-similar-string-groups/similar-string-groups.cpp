class Solution {
public:
    int findparent(int node,vector<int>&par){
        if(par[node]==node) return par[node];
        return par[node]=findparent(par[node],par);
    }
    bool unionfind(int u,int v,vector<int>&par,vector<int>&rank){
        int paru=findparent(u,par);
        int parv=findparent(v,par);
        if(paru==parv) return false;
        if(rank[paru]<rank[parv])par[paru]=parv;
        else if(rank[parv]<rank[paru])par[parv]=paru;
        else {
            rank[paru]++;
            par[parv]=paru;
        }
        return true;
    }
    bool aresimilar(string &s1,string& s2){
        int cnt=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])cnt++;
            if(cnt>2) return false;
        }
        if(cnt==0 or cnt==2) return true;
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        vector<int>par(strs.size()),rank(strs.size(),0);
        for(int i=0;i<strs.size();i++){
            par[i]=i;
        }
        int total=strs.size();
        int n=total;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(aresimilar(strs[i],strs[j])){
                    if(unionfind(i,j,par,rank))total--;
                }
            }
        }
        return total;
    }
};