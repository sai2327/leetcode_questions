class Solution {
public:
    long long ans=0;
    long long dfs(vector<bool>&vis,vector<vector<int>>&mat,int node,int seats){
        vis[node]=true;
        long long cnt=1;
        for(auto& v:mat[node]){
            if(!vis[v]){
                cnt+=dfs(vis,mat,v,seats);
            }
        }
        if(node!=0) ans+=(cnt+seats-1)/seats;
        return cnt; 
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>>mat(roads.size()+1);
        vector<bool>vis(roads.size()+1,false);
        for(auto & e:roads){
            mat[e[0]].push_back(e[1]);
            mat[e[1]].push_back(e[0]);
        }
        dfs(vis,mat,0,seats);
        return ans;
    }
};
