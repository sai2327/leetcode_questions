class Solution {
public:
    int countOrders(int n) {
        long long res=1;
        int mod=1e9+7;
        for(int i=2;i<=n;i++){
            res=(1ll*res*i*(2*i-1))%mod;
        }
        return res;
    }
};