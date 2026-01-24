class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string>res;
        while(ss>>word){
            res.push_back(word);
        }
        string ans="";
        if(res.empty()) return "";
        for(int i=(int)res.size()-1;i>=0;i--){
            ans+=res[i];
            if(i!=0) ans+=" ";
        }
        return ans;
    }
};