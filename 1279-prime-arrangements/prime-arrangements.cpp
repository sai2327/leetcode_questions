class Solution {
public:
    bool isprime(int n){
        if(n<2) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int numPrimeArrangements(int n) {
        int mod=1e9+7;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(isprime(i)) cnt++;
        }
        int m=n-cnt;
        long long res=1;
        for(int i=1;i<=m;i++){
            res=(1ll* (res)%mod*(i)%mod)%mod;
        }
        for(int i=1;i<=cnt;i++){
            res=(1ll*res*i)%mod;
        }
        return res;
    }
};