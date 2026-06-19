class Solution {
public:
    int countVowelPermutation(int n) {
        long long a=1,e=1,i=1,o=1,u=1,mod=1e9+7;
        for(int j=2;j<=n;j++){
            long long nexta=e%mod;
            long long nexte=(a+i)%mod;
            long long nexti=(a+e+o+u)%mod;
            long long nexto=(i+u)%mod;
            long long nextu=a%mod;
            a=nexta;
            e=nexte;
            i=nexti;
            o=nexto;
            u=nextu;
        }
        return (a+e+i+o+u)%mod;
    }
};