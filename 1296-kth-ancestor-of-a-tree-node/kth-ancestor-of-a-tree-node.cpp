class TreeAncestor {
public:
    vector<vector<int>>dp;
    TreeAncestor(int n, vector<int>& parent) {
        int m=log2(n)+1;
        dp.resize(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)dp[i][0]=parent[i];
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[j][i-1]!=-1) dp[j][i]=dp[dp[j][i-1]][i-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int i=0;
        while(k>0){
            if(node==-1)return node;
            if(k&1)node=dp[node][i];
            k/=2;
            i++;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */