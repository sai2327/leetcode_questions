class Solution {
public:
    int mod=1e9+7;
    int binexp(int a,int b,int m){
        int result=1;
        while(b >0){
            if(b & 1){
                result=(result*1ll*a)%m;
            }
            a=(a*1ll*a)%m;
            b>>=1;
        }
        return result;
    }
    int mod_divide(int a,int b){
        return (a*1ll*binexp(b,mod-2,mod))%mod;
    }
    int numberOfWays(int l, int r, int k) {
        int d=r-l,moves=(k - d); 
        if(moves%2 || k<d) return 0;
        vector<int> fact(k+1,1);
        for(int i=1;i<=k;i++){
            fact[i]=(fact[i-1]*1ll*i)%mod;
        }
        int f=d+moves/2;
        int b=moves/2;
        int total=fact[f+b];
        total=mod_divide(total,fact[f]);
        total=mod_divide(total,fact[b]);
        return total;
    }
};