class Solution {
public:
    long long lcm(long long x,long long y) {
        return (x*y)/gcd(x, y);
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long long low=1,high=2e9;
        long long ab=lcm(a,b),bc=lcm(b,c),ac=lcm(a,c);
        long long abc=lcm(ab,c),res=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long val=(mid/a)+(mid/b)+(mid/c)+(mid/abc)-(mid/ab)-(mid/bc)-(mid/ac);
            if(val>=n){
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }
};