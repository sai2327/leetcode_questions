class Solution {
public:
    bool hasAlternatingBits(int n) {
        int a,b;
        while(n/2){
            a=n&1;
            n>>=1;
            b=n&1;
            if(a==b) return false;
        }
        return true;
    }
};