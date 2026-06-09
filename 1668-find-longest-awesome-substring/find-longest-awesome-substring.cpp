class Solution {
public:
    int longestAwesome(string s) {
        int n=s.size(),res=0,cur=0;
        vector<int>seen(1024,-2);
        seen[0]=-1;
        for(int i=0;i<n;i++){
            cur^=(1<<(s[i]-'0'));
            if(seen[cur]!=-2) res=max(res,i-seen[cur]);
            for(int j=0;j<10;j++){
                int mask=cur^(1<<j);
                if(seen[mask]!=-2)res=max(res,i-seen[mask]);
            }
            if(seen[cur]==-2)seen[cur]=i;
        }
        return res;
    }
};