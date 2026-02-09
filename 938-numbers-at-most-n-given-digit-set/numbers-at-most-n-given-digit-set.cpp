class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s=to_string(n);
        int len=s.size(),d=digits.size(),res=0;
        for(int i=1;i<len;i++) res+=pow(d,i);
        for(int i=0;i<len ;i++){
            bool same_found=false;
            for(auto &digit:digits){
                if(digit[0]<s[i]) res+=pow(d,len-i-1);
                else if(digit[0]==s[i]) same_found=true;
            }
            if(!same_found) return res; 
        }
        return res+1;
    }
};