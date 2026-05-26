class Solution {
public:
    int solve(string &s,char ch,int k){
        int l=0,res=0,n=s.size(),cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]!=ch)cnt++;
            while(cnt>k){
                if(s[l]!=ch)cnt--;
                l++;
            }
            res=max(res,i-l+1);
        }
        return res;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve(answerKey,'F',k),solve(answerKey,'T',k));
    }
};