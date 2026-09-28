class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n=encoded.size();
        vector<int>perm(n+1);
        int x=0;
        for(int i=1;i<=n+1;i++) x^=i;
        for(int i=1;i<n;i+=2) x^=encoded[i];
        perm[0]=x;
        for(int i=0;i<n;i++) perm[i+1]=perm[i]^encoded[i];
        return perm;
    }
};