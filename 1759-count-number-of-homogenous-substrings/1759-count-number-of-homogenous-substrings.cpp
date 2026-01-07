class Solution {
public:
    int countHomogenous(string s) {
        int l=0,res=0,mod=1e9+7;;
        for(int r=0;r<s.size();r++){
            if(s[l]==s[r]){
                res+=r-l+1;
                res%=mod;
            }
            else{
                res+=1;
                res%=mod;
                l=r;
            }
        }
        return res%mod;
    }
};