class Solution {
public:
    int findNthDigit(int n) {
        int i=1,cnt=9,start=1;
        while(n>(long long)i*cnt){
            n-=i*cnt;
            i++;
            cnt*=10;
            start*=10;
        }
        int m=start+(n-1)/i;
        int digitIndex=(n-1)%i;
        string s=to_string(m);
        return s[digitIndex]-'0';
    }
};