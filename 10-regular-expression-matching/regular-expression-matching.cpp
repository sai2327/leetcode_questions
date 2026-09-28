class Solution {
public:
    int dp[21][21];
    bool rec(int i,string &s,int j,string &p){
        int pn=p.size(),sn=s.size();
        if(j==pn)return i==sn;
        if(dp[i][j]!=-1)return dp[i][j];
        if(j+1<pn and p[j+1]=='*'){
            if(rec(i,s,j+2,p) or (i<sn and (p[j]=='.' or s[i]==p[j]) and rec(i+1,s,j,p)))
                return dp[i][j]=1;
        }
        else if(i<sn and (p[j]=='.' or s[i]==p[j]) and rec(i+1,s,j+1,p))
            return dp[i][j]=1;
        return dp[i][j]=0;
    }
    bool isMatch(string s, string p){
        memset(dp,-1,sizeof(dp));
        return rec(0,s,0,p);
    }
};