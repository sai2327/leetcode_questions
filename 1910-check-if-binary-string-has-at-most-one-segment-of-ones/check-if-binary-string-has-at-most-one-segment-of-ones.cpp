class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        int i_0=0,i_1=n-1;
        while(s[i_0]=='1')i_0++;
        if(i_0==n)return 1;
        while(s[i_1]=='0') i_1--;
        return i_0>i_1;
    }
};