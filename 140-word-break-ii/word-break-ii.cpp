class Solution {
public:
    unordered_map<string,vector<string>>mp;
    vector<string> rec(string s,unordered_set<string>&st){
        //base case
        if(mp.count(s)) return mp[s];
        if(s.empty()) return{""};
        vector<string>res;
        for(int i=1;i<=s.size();i++){
            string pref=s.substr(0,i);
            if(st.count(pref)){
                string suff=s.substr(i);
                vector<string>sufftotal=rec(suff,st);
                for(string& a:sufftotal){
                    if(a.empty()){
                        res.push_back(pref);
                    } 
                    else{
                        res.push_back(pref+" " +a);
                    }
                }
            }
        }
        return mp[s]=res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        return rec(s,st);
    }
};