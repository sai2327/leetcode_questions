class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>mat(n,vector<int>(n,0));
        vector<int>cnt(n,0);
        for(auto& r:roads){
            int u=r[0],v=r[1];
            cnt[u]++;
            cnt[v]++;
            mat[u][v]=1;
            mat[v][u]=1;
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                //cout<<i<<"->"<<j<<"->"<<cnt[i]<<" "<<cnt[j]<<" "<<mat[i][j]<<endl;
                res=max(res,cnt[i]+cnt[j]-mat[i][j]);
            }
        }
        return res;
    }
};