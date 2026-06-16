class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<int,int>lastidx;
        for(int i=0;i<s.size();i++)lastidx[s[i]]=i;
        stack<char>st;
        string ans="";
        unordered_map<char,bool>vis;
        for(int i=0;i<s.size();i++){
            if(vis[s[i]])continue;
            while(!st.empty() and st.top()>s[i] and lastidx[st.top()]>i){
                vis[st.top()]=false;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]]=true;
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
         reverse(res.begin(),res.end());
        return res;
    }
};