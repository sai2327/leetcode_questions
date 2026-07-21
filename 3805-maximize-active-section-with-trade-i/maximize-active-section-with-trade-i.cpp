class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> a;
        int ones=0;
        s='1'+s+'1';
        // cout<<s;
        for(char c:s){
            if(c=='1')ones++;
        }
        int cnt=0,n=s.size();
        for(int i=0;i<n;i++){
            cnt++;
            if(i==n-1 or s[i]!=s[i+1]){
                if (s[i]=='0'){
                    a.push_back(-1*cnt);
                } 
                else{
                    a.push_back(cnt);
                }
                cnt=0;
            }
        }
        int maxi=0;
        for (int i=1;i<a.size()-1;i++){
            if (a[i]>0 && a[i-1]<0 && a[i+1]<0){
                int zeros=abs(a[i-1])+abs(a[i+1]);
                maxi=max(maxi,zeros);
            }
        }
        return ones+maxi-2;
    }
};