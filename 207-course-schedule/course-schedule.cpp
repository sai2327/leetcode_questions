class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& prerequisites) {
        vector<vector<int>>mat(num);
        vector<int>indeg(num);
        for(auto& pre:prerequisites){
            mat[pre[0]].push_back(pre[1]);
            indeg[pre[1]]++;
        }
        queue<int>q;
        for(int i=0;i<num;i++){
            if(indeg[i]==0) q.push(i);
        }
        int vis=0;
        while(!q.empty()){
            int u=q.front();
            vis++;
            q.pop();
            for(auto& v:mat[u]){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }
        return vis==num;
    }
};