class Solution {
public:
    long long countDistinct(long long n) {
        vector<long long>pow(16,1);
        string s=to_string(n);
        long long ans=0,i,m=s.size();
        for(int i=1;i<16;i++)pow[i]=pow[i-1]*9;
        for(int i=1;i<m;i++){
            ans+=pow[i];
            cout<<ans<<" ";
        }
        for(int i=0;i<=m;i++){
            if(s[i]=='0') break;
            for(long long j=1;j<s[i]-'0';j++) {
                ans+=pow[m-i-1];
                cout<<ans<<" ";
            }
            if(i>=s.size()) ans++;
        }       
        return ans;
    }
};