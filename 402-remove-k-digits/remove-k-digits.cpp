class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size()<= k) return "0";
        stack<char>st;
        string s=num;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            while(!st.empty() and s[i]<st.top() and k>0){
                st.pop();
                k--;
            }
             st.push(s[i]);
        }
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }
        string res="";
        while(st.size()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        int i=0;
        while(i<res.size()){
            if(res[i]=='0')i++;
            else break;
        }
        string a=string(res.begin()+i,res.end());
        if(a.size()==0)return "0";
        return a; 
    }
};