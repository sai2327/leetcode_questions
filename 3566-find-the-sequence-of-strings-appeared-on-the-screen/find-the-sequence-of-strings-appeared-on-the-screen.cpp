class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>res;
        string s="";
        for(char c:target){
            s+='a';
            res.push_back(s);
            while(s.back()!=c){
                s.back()=(s.back()=='z')?'a':s.back()+1;
                res.push_back(s);
            }
        }
        return res;
    }
};