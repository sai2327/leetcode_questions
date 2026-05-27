class Solution {
public:
    vector<string>res;
    void rec(int i,string str,string& digits,vector<string>&dig){
        if(i==digits.size()) {
            res.push_back(str);
            return;
        }
        for(char ch:dig[digits[i]-'0']){
            rec(i+1,str+ch,digits,dig);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>dig(10);
        dig[2]="abc";dig[3]="def";dig[4]="ghi";dig[5]="jkl";dig[6]="mno";
        dig[7]="pqrs";dig[8]="tuv";dig[9]="wxyz";
        rec(0,"",digits,dig);
        return res;
    }
};