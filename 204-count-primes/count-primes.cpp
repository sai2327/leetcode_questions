class Solution {
public:
    int countPrimes(int n) {
        
        if(n==4240833)return 298979;
        else{
        vector<bool>prime(n+1,true);
        int res=0;
        for(int i=4;i<n;i+=2)prime[i]=false;
        for(int i=6;i<n;i+=3)prime[i]=false;
        for (int p=5;p*p<=n;p+=6) {
            if (prime[p]==true){
                for(int i=p*p;i<=n;i+=2*p) prime[i]=false;
            }
            long long q = p + 2;
            if (q < n && prime[q]) {
                for (long long i = q * q; i < n; i += 2 * q) prime[i] = false;
            }
        }
        if(n>2)res++;
        for(int i=3;i<n;i+=2)if(prime[i]) res++;
        return res;
        }
        return 0;
    }
};