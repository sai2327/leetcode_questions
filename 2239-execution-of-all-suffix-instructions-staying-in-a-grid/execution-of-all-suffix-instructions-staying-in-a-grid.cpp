class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int>res(s.size());
        for(int i=0;i<s.size();i++){
            int cnt=0,a=startPos[0],b=startPos[1];
            for(int j=i;j<s.size();j++){
                char c=s[j];
                if(c=='R')b++;
                if(c=='L')b--;
                if(c=='U')a--;
                if(c=='D')a++;
                if(a<0 or a>=n or b<0 or b>=n)break;
                cnt++;
            }
            res[i]=cnt;
        }
        return res;
    }
};