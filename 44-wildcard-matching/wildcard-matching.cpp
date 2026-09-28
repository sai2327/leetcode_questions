class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0; 
        int j=0; 
        int k=-1; 
        int last_match = -1; 
        while(i<s.size()){
            if(j<p.size() && (s[i]==p[j] || p[j]=='?')){
                i++;
                j++;
            }
            else if(j<p.size() && p[j]=='*'){
                k=j;
                j++;
                last_match = i;
            }
            else if(k!=-1){
                j=k+1;
                last_match++;
                i=last_match;
            }
            else return false;
        }
        while (j < p.size() && p[j] == '*')j++;
        return j == p.size();
    }
};