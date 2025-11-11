class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        for(int i=1;i<n;i++){
            res=fun(res);
        }
        return res;
    }
    string fun(string s){
        int cnt=1;
        string res="";
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]) cnt++;
            else {
                res+=to_string(cnt)+s[i-1];
                cnt=1;
            }
        }
        res+=to_string(cnt)+s.back();
        return res;
    }
};