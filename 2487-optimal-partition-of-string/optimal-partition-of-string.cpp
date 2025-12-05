class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>st;
        int i=0,cnt=0;
        while(i<s.size()){
            if(st.count(s[i])!=1) {
                st.insert(s[i]);
            }
            else{
                cnt++;
                st.clear();
                st.insert(s[i]);
            }
            cout<<i<<" "<<cnt<<endl;
            i++;
        }
        return cnt+1;
    }
};