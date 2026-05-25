class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.size()-1]!='0') return false;
        vector<bool>dp(s.size(),false);
        dp[0]=true;
        int temp=0;
        for(int i=1;i<s.size();i++){
            if(i-minJump>=0 and dp[i-minJump]) temp++;
            if(i-maxJump-1>=0 and dp[i-maxJump-1]) temp--;
            dp[i]=(temp>0 and s[i]=='0');
           
        }
        return dp[s.size()-1];
    }
};