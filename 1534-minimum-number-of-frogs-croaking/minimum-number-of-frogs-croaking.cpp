class Solution {
public:
    unordered_map<char,int>mp;
    bool isvalid(){
        if(mp['c']>=mp['r'] and mp['r']>=mp['o'] and mp['o']>=mp['a'] and mp['a']>=mp['k']) return true;
        return false;
    }
    int minNumberOfFrogs(string croakOfFrogs) {
        int res=0,cnt=0;
        for(char i:croakOfFrogs){
            mp[i]++;
            if(!isvalid()){
                return -1;
            }
            if(i=='c') cnt++;
            else if(i=='k') cnt--;
            res=max(res,cnt);
        }
        if(mp['c']==mp['r'] and mp['o']==mp['r'] and mp['a']==mp['o'] and mp['k']==mp['o']) return res;
        else return -1;
        return res;
    }
};