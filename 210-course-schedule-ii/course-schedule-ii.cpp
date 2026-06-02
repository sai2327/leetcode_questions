class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<vector<int>>mat(num);
        vector<int>indeg(num);
        for(auto& e:pre){
            int u=e[0],v=e[1];
            mat[v].push_back(u);
            indeg[u]++;
        }
        vector<int>res;
        queue<int>q;
        for(int i=0;i<num;i++){
            if(indeg[i]==0)q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            res.push_back(u);
            for(int v:mat[u]){
                indeg[v]--;
                if(indeg[v]==0)q.push(v);
            }
        }
        if(res.size()!=num)
            return {};
        return res;
    }
};