class Solution {
public:
    long long removeZeros(long long n) {
        string s=to_string(n);
        string res="";
        for(auto i:s)if(i!='0') res+=i;
        long long ans=stoll(res);
        return ans;
    }
};