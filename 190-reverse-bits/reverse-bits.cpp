class Solution {
public:
    int reverseBits(int n) {
        long long ans=0;
        for(int i=0;i<32;i++){
            ans<<=1;
            if(n&1) ans|=1;
            n>>=1;
        }
        return int(ans);
    }
};