class Solution {
public:
    bool is(int x){
        int r=(int) sqrt(x);
        return r*r==x;
    }
    int numSquares(int n) {
        if(is(n)) return 1;
        for(int i=1;i*i<=n;i++){
            int j=n-i*i;
            if(is(j)) return 2;
        }
        int temp=n;
        while(temp%4==0) temp/=4;
        if(temp%8==7) return 4;
        return 3;
    }
};