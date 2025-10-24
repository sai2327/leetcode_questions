class Solution {
public:
    bool solve(int m){
        string s=to_string(m);
        vector<int>vec(10,0);
        for(auto i:s){
            vec[i-'0']++;
        }
        for(auto i:s){
            int c=i-'0';
            if(c==0 or vec[c]!=c) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        while(1){
            n++;
            if(solve(n)) return n;
        }
        return 0;
    }
};