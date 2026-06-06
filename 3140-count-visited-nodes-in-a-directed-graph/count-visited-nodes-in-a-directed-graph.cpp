class Solution {
public:
    int dfs(int node,vector<int>&edges,vector<int>&res){
        if(res[node]) return res[node];
        return res[node]=dfs(edges[node],edges,res)+1;
    }
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n=edges.size();
        vector<int>indeg(n),res(n);
        for(int i=0;i<n;i++){
            indeg[edges[i]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)if(indeg[i]==0) q.push(i);
        vector<bool>vis(n);
        while(!q.empty()){
            int u=q.front();
            vis[u]=true;
            q.pop();
            indeg[edges[u]]--;
            if(indeg[edges[u]]==0)q.push(edges[u]);
            // cout << u << " - \n";
        }
        
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            int ans=0;
            int k=i;
            while(indeg[k]!=0 and !vis[k]){
                
                ans++;
                vis[k]=true;
                k=edges[k];
            }
            k=i;
            while(res[k]==0){
                res[k]=ans;
                k=edges[k];
            }

        }
        //for(int i=0;i<n;i++) cout<<res[i]<<" ";
        for(int i=0;i<n;i++){
            if(res[i]==0){
                dfs(i,edges,res);
            }
        }
        return res;
    }
};