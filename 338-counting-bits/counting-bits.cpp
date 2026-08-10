class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res;
        for(int i=0;i<=n;i++){
            int m=i,cnt=0;
            while(m){
                if(m&1)cnt++;
                m>>=1;
            }
            res.push_back(cnt);
        }
        return res;
    }
};