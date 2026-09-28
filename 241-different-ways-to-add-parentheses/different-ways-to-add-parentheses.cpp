class Solution {
public:
    vector<int>solve(string s){
        vector<int>res;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='+' or c=='-' or c=='*'){
                vector<int>left=solve(s.substr(0,i));
                vector<int>right=solve(s.substr(i+1));
                for(int l:left){
                    for(int r:right){
                        if(c=='+')res.push_back(l+r);
                        else if(c=='-')res.push_back(l-r);
                        else res.push_back(l*r);
                    }
                }
            }
        }
        if(res.empty())res.push_back(stoi(s));
        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};