class Solution {
public:
    bool checkValidString(string s) {
        int mini=0,maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                mini++;
                maxi++;
            }
            else if(s[i]==')'){
                if(mini>0) mini--;
                maxi--;
            }
            else if(s[i]=='*'){
                maxi++;
                if(mini>0) mini--;
            }
            if(maxi<0) return false;
        }
        return mini==0;
    }
};