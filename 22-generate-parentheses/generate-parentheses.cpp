class Solution {
public:
    vector<string>res;
    void rec(string s,int open,int close){
        if(open==0 and close==0){
            res.push_back(s);
            return;
        }
        if(open>=1)rec(s+'(',open-1,close);
        if(close>open)rec(s+')',open,close-1);
    }
    vector<string> generateParenthesis(int n) {
        string s;
        rec(s,n,n);
        return res;
    }
};