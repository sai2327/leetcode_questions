class Solution {
public:
    int maxDistinct(string s) {
        vector<bool>a(26,false);
        for(char i:s){
            if(!a[i-'a'])a[i-'a']=true;
        }
        int cnt=0;
        for(auto i:a) if(i) cnt++;
        return cnt;
    }
};