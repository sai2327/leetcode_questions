class Solution {
public:
    int scoreOfParentheses(string s) {
        int res=0,sum=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') {
                sum++;
            }
            else{
                sum--;
                if(s[i-1]=='(') res+=pow(2,sum);
            }
        }
        return res+sum;
    }
};