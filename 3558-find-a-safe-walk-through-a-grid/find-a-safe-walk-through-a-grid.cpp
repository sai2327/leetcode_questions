class Solution{
public:
    int dp[52][52][102];
    bool dfs(int r,int c,int hp,vector<vector<int>>&g,vector<vector<bool>>&vis){
        if(hp<=0)return false;
        if(r==g.size()-1&&c==g[0].size()-1)return true;
        if(dp[r][c][hp]!=-1)return dp[r][c][hp];
        vis[r][c]=1;
        bool ok=0;
        if(c-1>=0&&!vis[r][c-1]) ok|=dfs(r,c-1,g[r][c-1]?hp-1:hp,g,vis);
        if(!ok&&c+1<g[0].size()&&!vis[r][c+1]) ok|=dfs(r,c+1,g[r][c+1]?hp-1:hp,g,vis);
        if(!ok&&r-1>=0&&!vis[r-1][c]) ok|=dfs(r-1,c,g[r-1][c]?hp-1:hp,g,vis);
        if(!ok&&r+1<g.size()&&!vis[r+1][c]) ok|=dfs(r+1,c,g[r+1][c]?hp-1:hp,g,vis);
        vis[r][c]=0;
        return dp[r][c][hp]=ok;
    }
    bool findSafeWalk(vector<vector<int>>&g,int hp){
        vector<vector<bool>>vis(g.size(),vector<bool>(g[0].size()));
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,g[0][0]?hp-1:hp,g,vis);
    }
};