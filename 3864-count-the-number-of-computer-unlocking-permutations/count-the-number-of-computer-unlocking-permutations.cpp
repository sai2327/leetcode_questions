class Solution {
public:
    int countPermutations(vector<int>& comp) {
        int mod=1e9+7;
        int n=comp.size();
        int first=comp[0];
            long long fact=1;
        for(int i=1;i<n;i++){
            if(comp[i]<=first) return 0;
            
        }
        for(int i=2;i<n;i++) fact=(fact*i)%mod;
        return fact;
    }
};