class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int>res(word.size(),0);
        long long temp=0;
        for(int i=0;i<word.size();i++){
            temp=(temp*10+(word[i]-'0'))%m;
            if(temp==0)res[i]=1;
        }
        return res;
    }
};