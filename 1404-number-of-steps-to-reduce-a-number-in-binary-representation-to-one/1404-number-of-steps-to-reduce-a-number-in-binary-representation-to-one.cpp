class Solution {
public:
    int numSteps(string s) {
        int l=s.size()-1,carry=0,cnt=0;
        while(l>0){
            if(s[l]-'0'+carry==0){
                carry=0;
                cnt++;
            }
            else if(s[l]-'0' +carry==2){
                carry=1;
                cnt++;
            }
            else{
                carry=1;
                cnt+=2;
            }
            l--;
        }
        if(carry==1) cnt++;
        return cnt;
    }
};